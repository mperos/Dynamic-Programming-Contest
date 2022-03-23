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

const int MAXN = 1e3 + 500;
const int MAXV = 1e4 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const double EPS = 1e-9;
const double PI = 3.1415926535;
const int OFF = 1 << 17;

struct triple {
    int weight;
    int solidness;
    int value;
};

vector <triple> blocks;
ll dp[MAXN][MAXV];

int main() {
    int N, w, s, v, ind;
    int weight, solidness, value;

    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d%d%d", &w, &s, &v);
        blocks.push_back(triple{w, s, v});
    }

    sort(blocks.begin(), blocks.end(), [](const triple& a, const triple& b) {
        return (a.solidness + a.weight > b.solidness + b.weight);
    });

    dp[0][blocks[0].solidness] = blocks[0].value;
    for(int i = 1; i < N; i++) {
        weight = blocks[i].weight;
        solidness = blocks[i].solidness;
        value = blocks[i].value;

        dp[i][solidness] = value;
        for(int j = 0; j < MAXV - 10; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);     // preskocis objekt
            if(!dp[i - 1][j] || j < weight)
                continue;

            ind = min(j - weight, solidness);           // stavis objekt
            dp[i][ind] = max(dp[i][ind], dp[i - 1][j] + value);
        }
    }

    ll ans = 0;
    for(int i = 0; i < MAXV; i++)
        ans = max(ans, dp[N - 1][i]);
    printf("%lld\n", ans);

    return 0;
}

