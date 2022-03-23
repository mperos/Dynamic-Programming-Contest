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

const int MAXN = 105;
const int MAXK = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;
const int LOG = 18;
const double EPS = 1e-9;
const double PI = 3.1415926535;

ll candies[MAXN];
ll prefix[MAXK];
ll dp[MAXN][MAXK];

ll add(ll a, ll b) {
    return (a + b) % MOD;
}

ll subt(ll a, ll b) {
    return (a - b + MOD) % MOD;
}

void preprocess(int N) {
    prefix[0] = 1;
    for(int i = 0; i <= candies[0]; i++)
        dp[0][i] = 1;
    for(int i = 0; i < N; i++)
        dp[i][0] = 1;
}

int main() {
    int N, K;

    cin >> N >> K;
    for(int i = 0; i < N; i++)
        cin >> candies[i];

    preprocess(N);
    for(int i = 1; i < N; i++) {
        for(int j = 1; j <= K; j++)
            prefix[j] = add(prefix[j - 1], dp[i - 1][j]);

        for(int j = 1; j <= K; j++)
            if(candies[i] + 1 > j)
                dp[i][j] = prefix[j];
            else
                dp[i][j] = subt(prefix[j], prefix[j - candies[i] - 1]);
    }

    cout << dp[N - 1][K] << endl;

    return 0;
}
