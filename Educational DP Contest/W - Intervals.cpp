#include <bits/stdc++.h>

#define left first
#define value second

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

const int MAXN = 2e5 + 500;
const int OFF = 1 << 18;

vector <pii> intervals[MAXN];
ll dp[MAXN], tree[2 * OFF], prop[2 * OFF];

void update(int i, int l, int r, int ql, int qr, ll val) {
    if(ql <= l && r <= qr) {
        tree[i] += val;
        prop[i] += val;
        return;
    }

    if(r < ql || qr < l)
        return;

    update(2 * i, l, (l + r) / 2, ql, qr, val);
    update(2 * i + 1, (l + r) / 2 + 1, r, ql, qr, val);
    tree[i] = max(tree[2 * i], tree[2 * i + 1]) + prop[i];
}

int main() {
    int N, M, l, r, val;

    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++) {
        scanf("%d%d%d", &l, &r, &val);
        intervals[r - 1].push_back({l - 1, val});
    }

    for(int i = 0; i < N; i++) {
        dp[i] = tree[1];
        update(1, 0, OFF - 1, i, i, dp[i]);
        for(auto interval : intervals[i])
            update(1, 0, OFF - 1, interval.left, i, interval.value);
    }

    printf("%lld\n", tree[1]);

    return 0;
}
