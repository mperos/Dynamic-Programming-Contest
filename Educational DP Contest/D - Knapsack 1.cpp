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

const int MAXN = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const double EPS = 1e-9;
const double PI = 3.1415926535;

ll dp[105][MAXN], w[105], v[105];

int main() {
    ll N, W, ans = 0;

    cin >> N >> W;
    for(int i = 1; i <= N; i++)
        cin >> w[i] >> v[i];

    for(int i = 1; i <= N; i++)
        for(int j = 0; j <= W; j++)
            if(j < w[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);

    for(int i = 0; i <= W; i++)
        ans = max(ans, dp[N][i]);
    cout << ans << endl;

    return 0;
}

