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

const int MAXN = 1500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const double EPS = 1e-9;
const double PI = 3.1415926535;

char grid[MAXN][MAXN];
ll dp[MAXN][MAXN];

ll add(ll a, ll b) {
    return (a + b) % MOD;
}

int main() {
    int H, W;

    cin >> H >> W;
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
            cin >> grid[i][j];

    dp[0][0] = 1;
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++) {
            if(grid[i][j] == '#')
                continue;
            if(i > 0)
                dp[i][j] = add(dp[i][j], dp[i - 1][j]);
            if(j > 0)
                dp[i][j] = add(dp[i][j], dp[i][j - 1]);
        }

    cout << dp[H - 1][W - 1] << endl;

    return 0;
}
