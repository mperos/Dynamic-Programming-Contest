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

int dp[MAXN][3], hep[MAXN][3];

int main() {
    int N;
    memset(dp, INF, sizeof(dp));

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> hep[i][0] >> hep[i][1] >> hep[i][2];

    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(int i = 1; i <= N; i++) {
        dp[i][0] = max(hep[i - 1][1] + dp[i - 1][1], hep[i - 1][2] + dp[i - 1][2]);
        dp[i][1] = max(hep[i - 1][0] + dp[i - 1][0], hep[i - 1][2] + dp[i - 1][2]);
        dp[i][2] = max(hep[i - 1][0] + dp[i - 1][0], hep[i - 1][1] + dp[i - 1][1]);
    }

    cout << max(max(dp[N][0], dp[N][1]), dp[N][2]) << endl;

    return 0;
}

