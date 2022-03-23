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

const int MAXN = 3500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const double EPS = 1e-9;
const double PI = 3.1415926535;

double coins[MAXN];
double dp[MAXN][MAXN];

int main() {
    int N;
    double ans = 0;

    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> coins[i];

    dp[0][0] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            dp[i][j] += dp[i - 1][j] * (1 - coins[i]);
            if(j == 0) continue;
            dp[i][j] += dp[i - 1][j - 1] * coins[i];
        }
    }

    for(int j = (N + 1) / 2; j <= N; j++)
        ans += dp[N][j];
    printf("%0.10f\n", ans);

    return 0;
}

