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
const ll INF = 1e13;
const int MOD = 1e9 + 7;
const int LOG = 18;
const double EPS = 1e-9;
const double PI = 3.1415926535;

ll dp[MAXN][MAXN];
ll a[MAXN];

int main() {
    int N;

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> a[i];

    for(int i = 0; i < N; i++)
        dp[i][i] = a[i];

    for(int len = 2; len <= N; len ++) {
        for(int l = 0; l <= N - len; l++) {
            int r = l + len - 1;
            dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
        }
    }

    cout << dp[0][N - 1] << endl;

    return 0;
}
