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

const int MAXN = 22;
const int BITMASK = (1 << MAXN);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const double EPS = 1e-9;
const double PI = 3.1415926535;

int pairing[MAXN][MAXN];
int dp[BITMASK];

// stanje je samo koja su mjesta zauzeta
// broj znamenaka maske kaze nan na kojen smo muskarcu
// maska nan kaze koje smo zene zauzeli

int add(int a, int b) {
    if(a + b >= MOD)
        return (a + b - MOD);
    return (a + b);
}

int main() {
    int N, MASK;

    scanf("%d", &N);
    MASK = (1 << N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &pairing[i][j]);

    dp[0] = 1;
    for(int mask = 1; mask < MASK; mask++) {
        int i = __builtin_popcount(mask) - 1;
        for(int j = 0; j < N; j++)
            if((mask & (1 << j)) && pairing[i][j])
                dp[mask] = add(dp[mask], dp[mask ^ (1 << j)]);
    }

    printf("%d\n", dp[MASK - 1]);

    return 0;
}

