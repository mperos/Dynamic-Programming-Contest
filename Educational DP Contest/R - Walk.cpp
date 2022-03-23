#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

const int MAXN = 55;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const double EPS = 1e-9;
const double PI = 3.1415926535;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef vector < ll > vl;

ll matrix[MAXN][MAXN];
ll ans[MAXN][MAXN];

ll add(ll a, ll b) {
    if(a + b >= MOD)
        return (a + b - MOD);
    return (a + b);
}

ll mult(ll a, ll b) {
    return (a * b) % MOD;
}

void matrix_mult(ll A[][MAXN], ll B[][MAXN], int N) {
    ll temp[MAXN][MAXN];
    memset(temp, 0, sizeof(temp));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)
                temp[i][j] = add(temp[i][j], mult(A[i][k], B[k][j]));

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            A[i][j] = temp[i][j];
}

ll solution(int N, ll y) {
    for(int i = 0; i < N; i++)
        ans[i][i] = 1;

    while(y > 0) {
        if(y & 1)
            matrix_mult(ans, matrix, N);

        y = y >> 1;
        matrix_mult(matrix, matrix, N);
    }

    ll sol = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            sol = add(sol, ans[i][j]);

    return sol;
}

int main() {
    ll N, K;
    cin >> N >> K;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> matrix[i][j];

    cout << solution(N, K) << endl;

    return 0;
}

