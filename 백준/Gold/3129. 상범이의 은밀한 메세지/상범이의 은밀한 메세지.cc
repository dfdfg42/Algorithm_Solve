#include <iostream>
#include <vector>
#include <string>
using namespace std;

string a, b;
vector<int> key;
int keyLen = 0;


bool checkSync(int index) {
    int L = b.length();
    vector<int> diff(L);

    for (int i = 0; i < L; i++) {
        int ca = a[index + i] - 'a';
        int cb = b[i] - 'a';
        diff[i] = (ca - cb + 26) % 26;
    }

    for (int P = 1; P <= L / 2; P++) {
        bool ok = true;
        for (int i = P; i < L; i++) {
            if (diff[i] != diff[i - P]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            keyLen = P;
            key.assign(diff.begin(), diff.begin() + P);
            return true;
        }
    }
    return false;
}


string recoverOri() {
    int N = a.length();
    string orig(N, 'a');
    for (int i = 0; i < N; i++) {
        int ca = a[i] - 'a';
        int k = key[i % keyLen];
        orig[i] = char((ca - k + 26) % 26 + 'a');
    }
    return orig;
}


void solve() {
    cin >> a >> b;
    int N = a.length(), L = b.length();

    for (int i = 0; i <= N - L; i++) {
        if (checkSync(i)) {

            vector<int> key_part = key;

            vector<int> true_key(keyLen);

            for (int j = 0; j < keyLen; j++) {
                int true_key_index = (i + j) % keyLen;
                true_key[true_key_index] = key_part[j];
            }

            key = true_key;

            cout << recoverOri() << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}