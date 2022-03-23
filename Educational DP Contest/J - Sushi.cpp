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

const int MAXN = 305;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const double EPS = 1e-9;
const double PI = 3.1415926535;

double dp[MAXN][MAXN][MAXN];
double prob_empty, prob_one, prob_two, prob_three;

int main() {
    int N, x, n1, n2, n3;

    cin >> N;
    n1 = n2 = n3 = 0;
    for(int i = 0; i < N; i++) {
        cin >> x;
        if(x == 1) n1 ++;
        if(x == 2) n2 ++;
        if(x == 3) n3 ++;
    }

    for(int k = 0; k <= N; k++) {
        for(int j = 0; j <= N; j++) {
            for(int i = 0; i <= N; i++) {
                if(i == 0 && j == 0 && k == 0)
                    continue;
                if(i + j + k > MAXN)
                    continue;

                prob_empty = N / (double)(i + j + k);
                prob_one = i / (double)(i + j + k);
                prob_two = j / (double)(i + j + k);
                prob_three = k / (double)(i + j + k);

                if(i != 0)
                    dp[i][j][k] += prob_one * dp[i - 1][j][k];
                if(j != 0)
                    dp[i][j][k] += prob_two * dp[i + 1][j - 1][k];
                if(k != 0)
                    dp[i][j][k] += prob_three * dp[i][j + 1][k - 1];
                dp[i][j][k] += prob_empty;
            }
        }
    }

    printf("%.10f\n", dp[n1][n2][n3]);

    return 0;
}
