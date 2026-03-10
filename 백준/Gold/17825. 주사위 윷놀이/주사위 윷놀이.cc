#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dice[10];
int horse[4]; // 4개 말의 현재 위치(노드 번호)
int score[33];
int next_node[33];
int shortcut[33];
bool occupied[33];
int max_score = 0;

void map_init() {
	for (int i = 0; i <= 19; i++) next_node[i] = i + 1;
	next_node[20] = 32; 
	for (int i = 0; i <= 20; i++) score[i] = i * 2;


	shortcut[5] = 21; 
	score[21] = 13; score[22] = 16; score[23] = 19;
	next_node[21] = 22; next_node[22] = 23; next_node[23] = 24;

	shortcut[10] = 25; 
	score[25] = 22; score[26] = 24;
	next_node[25] = 26; next_node[26] = 24;

	shortcut[15] = 27; 
	score[27] = 28; score[28] = 27; score[29] = 26;
	next_node[27] = 28; next_node[28] = 29; next_node[29] = 24;


	score[24] = 25; score[30] = 30; score[31] = 35;
	next_node[24] = 30; next_node[30] = 31; next_node[31] = 20;

	score[32] = 0; // 도착 칸 점수
	next_node[32] = 32; 
}

void solve(int turn, int current_score) {
	if (turn == 10) {
		max_score = max(max_score, current_score);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int prev_pos = horse[i];
		if (prev_pos == 32) continue;

		int next_pos = prev_pos;
		int move_cnt = dice[turn];

		if (shortcut[next_pos] > 0) {
			next_pos = shortcut[next_pos];
			move_cnt--;
		}

		while (move_cnt--) {
			next_pos = next_node[next_pos];
		}

		if (next_pos != 32 && occupied[next_pos]) continue;

		occupied[prev_pos] = false;
		occupied[next_pos] = true;
		horse[i] = next_pos;

		solve(turn + 1, current_score + score[next_pos]);

		horse[i] = prev_pos;
		occupied[next_pos] = false;
		occupied[prev_pos] = true;
	}
}

int main() {
	for (int i = 0; i < 10; i++) cin >> dice[i];
	map_init();
	solve(0, 0);
	cout << max_score << endl;
	return 0;
}