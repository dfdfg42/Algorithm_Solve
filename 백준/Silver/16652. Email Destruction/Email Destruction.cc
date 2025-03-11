#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// 'Re: ' 의 반복 횟수와 원래 주제를 분리하는 함수
pair<int, string> parseSubject(const string& s) {
    int cnt = 0;
    size_t pos = 0;
    string prefix = "Re: ";
    while (s.substr(pos, 4) == prefix) {
        cnt++;
        pos += 4;
    }
    return make_pair(cnt, s.substr(pos));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    unordered_map<string, int> max_chain_length;

    string dummy;
    getline(cin, dummy); // 개행 문자 제거

    for (int i = 0; i < k; ++i) {
        string subject;
        getline(cin, subject);

        pair<int, string> parsed = parseSubject(subject);
        int re_count = parsed.first;
        string base_subject = parsed.second;

        // 각 체인의 최대 길이를 기록
        if (max_chain_length[base_subject] < re_count + 1) {
            max_chain_length[base_subject] = re_count + 1;
        }
    }

    // 최소 필요 이메일 개수 계산
    int min_emails_required = 0;
    for (unordered_map<string, int>::iterator it = max_chain_length.begin(); it != max_chain_length.end(); ++it) {
        min_emails_required += it->second;
    }

    // 추정한 n보다 최소 필요 이메일 개수가 작거나 같아야 함
    if (min_emails_required <= n) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}
