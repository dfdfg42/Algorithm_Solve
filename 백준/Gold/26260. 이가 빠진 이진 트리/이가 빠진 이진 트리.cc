#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> sortedVal;     
vector<ll> tree;             

void build(int idx, int l, int r)
{
    if (l > r) return;
    int m = (l + r) / 2;          // 중앙값 → 현재 노드
    tree[idx] = sortedVal[m];
    build(idx * 2, l, m - 1); // 왼쪽 서브트리
    build(idx * 2 + 1, m + 1, r);   // 오른쪽 서브트리
}

void postorder(int idx, int n)
{
    if (idx > n) return;
    postorder(idx * 2, n);
    postorder(idx * 2 + 1, n);
    cout << tree[idx] << ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;                 
    cin >> N;

    sortedVal.resize(N);
    int hole = -1;          
    for (int i = 0; i < N; ++i) {
        cin >> sortedVal[i];
        if (sortedVal[i] == -1) hole = i;
    }

    ll X; cin >> X;
    sortedVal[hole] = X;    
    sort(sortedVal.begin(), sortedVal.end());

    tree.assign(N + 1, 0); 
    build(1, 0, N - 1);    
    postorder(1, N);        
    cout << '\n';
}
