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

const int MAXN = 2e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const double EPS = 1e-9;
const double PI = 3.1415926535;
const int OFF = 1 << 17;

struct block {
    int r, c;
};

vector <block> blocks;
int fact[MAXN];
int mult_inv[MAXN];
int dp[3005];

ll add(const ll& a, const ll& b) {
    if(a + b >= MOD)
        return (a + b - MOD);
    return (a + b);
}

ll subt(const ll& a, const ll& b) {
    if(a - b < 0)
        return (a - b + MOD);
    return (a - b);
}

ll mult(const ll& a, const ll& b) {
    return (a * b) % MOD;
}

ll power(int a, int N) {
    int res = 1;
    while(N > 0) {
        if(N & 1)
            res = mult(res, a);
        N = (N >> 1);
        a = mult(a, a);
    }
    return res;
}

void preprocess() {
    fact[0] = 1;
    mult_inv[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        fact[i] = mult(i, fact[i - 1]);
        mult_inv[i] = power(fact[i], MOD - 2);  // a^(-1) = a^(MOD - 2) (% MOD)
    }
}

ll choose(int N, int K) {
    if(N < 0 || K < 0 || N < K)
        return 0;
    return mult(fact[N], mult(mult_inv[K], mult_inv[N - K]));
}

int main() {
    preprocess();
    int H, W, N;
    int r, c, c1, r1;

    scanf("%d%d%d", &H, &W, &N);
    for(int i = 0; i < N; i++) {
        scanf("%d%d", &r, &c);
        blocks.push_back(block{r, c});
    }

    blocks.push_back(block{H, W});
    sort(blocks.begin(), blocks.end(), [](const block& a, const block& b) {
        return (a.r + a.c < b.r + b.c);
    });

    // counting on first block contacted
    for(int i = 0; i <= N; i++) {
        c = blocks[i].c;
        r = blocks[i].r;
        dp[i] = choose(r + c - 2, r - 1);
        for(int j = 0; j < i; j++) {
            c1 = blocks[j].c;
            r1 = blocks[j].r;
            if(r1 <= r && c1 <= c)
                dp[i] = subt(dp[i], mult(dp[j], choose(r - r1 + c - c1, r - r1)));
        }
    }

    cout << dp[N] << endl;

    return 0;
}

