#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


struct User {
    int id;
    int solved = 0;
    int penalty = 0;
    int lastSubmitTime = 0;
    int lastRank = 0;
    int reversalPts = 0;
};


struct FreezeEvent {
    int time;
    int id;
    int prob;
    int submitCnt;
};

bool cmpUser(const User* a, const User* b) {
    if (a->solved != b->solved)
        return a->solved > b->solved;
    if (a->penalty != b->penalty)
        return a->penalty < b->penalty;
    return a->lastSubmitTime < b->lastSubmitTime;
}

int timeToMin(const string& s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    return h * 60 + m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<User> users(N + 1);
    for (int i = 1; i <= N; i++) {
        users[i].id = i;
    }

    const int FREEZE_START = 3 * 60;
    vector<FreezeEvent> events;
    events.reserve(M);

    // 모든 제출 이력 처리
    for (int i = 0; i < M; i++) {
        string ts;
        int pid, prob, cnt;
        cin >> ts >> pid >> prob >> cnt;
        int t = timeToMin(ts);

        if (t <= FREEZE_START) { 
            users[pid].solved++;
            users[pid].penalty += t + (cnt - 1) * 20;
            users[pid].lastSubmitTime = t;
        }
        else { 
            events.push_back({ t, pid, prob, cnt });
        }
    }


    vector<User*> ranking;
    ranking.reserve(N);
    for (int i = 1; i <= N; i++) {
        ranking.push_back(&users[i]);
    }
    sort(ranking.begin(), ranking.end(), cmpUser);
    for (int i = 0; i < N; i++) {
        ranking[i]->lastRank = i;
    }


    vector<bool> revealed(events.size(), false);
    int remainingEvents = events.size();

    while (remainingEvents > 0) {

        int worstRank = -1;
        int targetPid = -1;
        for (size_t i = 0; i < events.size(); i++) {
            if (!revealed[i]) {
                int currentRank = users[events[i].id].lastRank;
                if (currentRank > worstRank) {
                    worstRank = currentRank;
                    targetPid = events[i].id;
                }
            }
        }

        int eventIdxToReveal = -1;
        int min_problem_num = INT_MAX;
        for (size_t i = 0; i < events.size(); i++) {
            if (!revealed[i] && events[i].id == targetPid) {
                if (events[i].prob < min_problem_num) {
                    min_problem_num = events[i].prob;
                    eventIdxToReveal = i;
                }
            }
        }


        revealed[eventIdxToReveal] = true;
        remainingEvents--;

        int pid = events[eventIdxToReveal].id;
        int t = events[eventIdxToReveal].time;
        int cnt = events[eventIdxToReveal].submitCnt;

        users[pid].solved++;
        users[pid].penalty += t + (cnt - 1) * 20;
        users[pid].lastSubmitTime = t;


        sort(ranking.begin(), ranking.end(), cmpUser);
        for (int i = 0; i < N; i++) {
            User* u = ranking[i];
            int rankChange = u->lastRank - i;
            if (rankChange > 0) {
                u->reversalPts += rankChange;
            }
            u->lastRank = i; 
        }
    }

    int winner = 1;
    for (int i = 2; i <= N; i++) {
        if (users[i].reversalPts > users[winner].reversalPts) {
            winner = i;
        }
        else if (users[i].reversalPts == users[winner].reversalPts) {
            if (users[i].lastRank < users[winner].lastRank) {
                winner = i;
            }
        }
    }

    cout << winner << "\n";

    return 0;
}