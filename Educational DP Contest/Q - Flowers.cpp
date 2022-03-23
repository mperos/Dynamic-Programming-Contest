#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef vector < ll > vl;

const int MAXN = 300500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const double EPS = 1e-9;
const double PI = 3.1415926535;

int height[MAXN];
int value[MAXN];
ll dp[MAXN];

struct segment_tree {
    ll tree[2 * MAXN];

    void update(int pos, ll val) {
        for(; pos >= 1; pos = pos / 2)
            tree[pos] = max(tree[pos], val);
    }

    ll query(int pos) {
        ll best = 0;
        for(; pos > 1; pos = pos / 2)
            if(pos % 2 == 1)
                best = max(best, tree[pos - 1]);
        return best;
    }
};

int base(int n) {
    int k = 1;
    while(k <= n) {
        k = k * 2;
    }
    return k;
}

int main() {
    int N, b;
    segment_tree T;

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> height[i];
    for(int i = 0; i < N; i++)
        cin >> value[i];

    b = base(N);
    for(int i = 0; i < N; i++) {
        int pos = b + height[i];
        ll best = T.query(pos);
        dp[height[i]] = best + value[i];
        T.update(pos, dp[height[i]]);
    }

    ll ans = 0;
    for(int i = 0; i <= N; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;

    return 0;
}
