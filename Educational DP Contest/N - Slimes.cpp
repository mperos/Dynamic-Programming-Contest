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

const int MAXN = 405;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const double EPS = 1e-9;
const double PI = 3.1415926535;

ll dp[MAXN][MAXN];
ll slime[MAXN];
ll prefix[MAXN];

void preprocess(int N) {
    memset(dp, INF, sizeof(dp));
    for(int i = 0; i < N; i++)
        dp[i][i] = 0;

    prefix[0] = 0;
    for(int i = 1; i <= N; i++)
        prefix[i] = prefix[i - 1] + slime[i - 1];
}

int main() {
    int N;

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> slime[i];

    preprocess(N);
    for(int len = 2; len <= N; len++) {
        for(int l = 0; l <= N - len; l++) {
            int r = l + len - 1;
            for(int k = l; k <= r - 1; k++)
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
            dp[l][r] += prefix[r + 1] - prefix[l];
        }
    }

    cout << dp[0][N - 1] << endl;

    return 0;
}

