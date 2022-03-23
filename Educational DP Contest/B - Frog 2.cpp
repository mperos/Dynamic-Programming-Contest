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

int dp[MAXN], h[MAXN];

int main() {
    int N, K;
    memset(dp, INF, sizeof(dp));

    cin >> N >> K;
    for(int i = 0; i < N; i++)
        cin >> h[i];

    dp[0] = 0;
    for(int i = 1; i <= K; i++)
        dp[i] = abs(h[i] - h[0]);

    for(int i = K + 1; i < N; i++)
        for(int j = 1; j <= K; j++)
            dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));

    cout << dp[N - 1] << endl;

    return 0;
}
