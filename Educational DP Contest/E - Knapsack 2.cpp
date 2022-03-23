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

const int NUM = 105;
const int MAXN = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const double EPS = 1e-9;
const double PI = 3.1415926535;

int dp[NUM][MAXN];
int w[NUM], v[NUM];

int main() {
    int N, W, V = 0;

    cin >> N >> W;
    for(int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
        V += v[i];
    }

    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= N; i++)
        for(int j = 0; j <= V; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j < v[i])
                continue;
            if(dp[i - 1][j - v[i]] + w[i] <= W)
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
        }

    for(int i = V; i >= 0; i--)
        if(dp[N][i] != INF) {
            cout << i << endl;
            break;
        }

    return 0;
}

