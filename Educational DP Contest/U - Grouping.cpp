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

ll dp[MAXN];
ll group_value[MAXN];
ll M[20][20];

void init_groups(int N) {
    for(int mask = 0; mask < (1 << N); mask++) {
        for(int i = 0; i < N; i++) {
            if((mask >> i) & 1) {
                for(int j = i + 1; j < N; j++)
                    if((mask >> j) & 1)
                        group_value[mask] += M[i][j];
            }
        }
    }
}

void rec(int i, const vector <int>& not_used, ll score, int mask, int group_mask) {
    if(i == not_used.size()) {
        dp[mask] = max(dp[mask], score + group_value[group_mask]);
        return;
    }

    rec(i + 1, not_used, score, mask, group_mask);          // nisi iskoristija trenutni element
    rec(i + 1, not_used, score, mask + (1 << not_used[i]), group_mask + (1 << not_used[i]));     // iskoristija si trenutni element
}

int main() {
    int N, last;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%lld", &M[i][j]);

    init_groups(N);
    for(int mask = 0; mask < (1 << N); mask++) {
        vector <int> not_used;
        for(int i = 0; i < N; i++)
            if(!((mask >> i) & 1))
                not_used.push_back(i);

        rec(0, not_used, dp[mask], mask, 0);
    }

    cout << dp[(1 << N) - 1] << endl;

    return 0;
}

