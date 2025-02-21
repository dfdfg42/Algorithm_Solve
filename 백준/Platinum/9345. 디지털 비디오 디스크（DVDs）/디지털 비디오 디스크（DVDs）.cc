#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

typedef long long ll;

struct Node {
    ll mn, mx;
};

int n, k;
vector<Node> tree;
vector<ll> arr;  // DVD 번호 저장 (초기에는 1~n)

Node combine(const Node &left, const Node &right) {
    Node res;
    res.mn = min(left.mn, right.mn);
    res.mx = max(left.mx, right.mx);
    return res;
}

void build() {
    // 리프 노드 채우기: tree[n]부터 tree[2*n-1]까지
    for (int i = 0; i < n; i++) {
        tree[n + i] = {arr[i], arr[i]};
    }
    // 내부 노드 계산: 부모 = combine(왼쪽, 오른쪽)
    for (int i = n - 1; i > 0; i--) {
        tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
    }
}

void updateTree(int pos, ll value) {
    pos += n;
    tree[pos] = {value, value};
    while (pos > 1) {
        pos >>= 1;
        tree[pos] = combine(tree[pos << 1], tree[pos << 1 | 1]);
    }
}

Node query(int left, int right) {
    // 초기값: 최소값은 최댓값, 최대값은 최솟값으로 설정 (identity element)
    Node resLeft = {numeric_limits<ll>::max(), numeric_limits<ll>::min()};
    Node resRight = {numeric_limits<ll>::max(), numeric_limits<ll>::min()};
    left += n;
    right += n;
    while (left <= right) {
        if (left & 1) {
            resLeft = combine(resLeft, tree[left]);
            left++;
        }
        if (!(right & 1)) {
            resRight = combine(tree[right], resRight);
            right--;
        }
        left >>= 1;
        right >>= 1;
    }
    return combine(resLeft, resRight);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        arr.resize(n);
        tree.assign(2 * n, {0, 0});
        
        // 초기 DVD 번호: 1 ~ n (즉, 0번 선반에 1번 DVD, 1번 선반에 2번 DVD, ...)
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }
        
        build();

        for (int i = 0; i < k; i++) {
            int q, a, b;
            cin >> q >> a >> b;
            if (q == 0) {
                // 선반 a와 선반 b의 DVD를 교환
                ll tempA = tree[n + a].mn;
                ll tempB = tree[n + b].mn;
                updateTree(a, tempB);
                updateTree(b, tempA);
            }
            else if (q == 1) {
                Node res = query(a, b);
                // 올바른 DVD 집합은 선반 a부터 b에 대해 {a+1, a+2, ..., b+1}이 있어야 함.
                // 따라서 최소값은 a+1, 최대값은 b+1이고, 두 값의 차이가 (b-a)여야 함.
                if (res.mn == a + 1 && res.mx == b + 1 && (res.mx - res.mn + 1 == b - a + 1))
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }
    
    return 0;
}
