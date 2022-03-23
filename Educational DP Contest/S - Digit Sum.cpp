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

const int MAXD = 105;
const int MAXN = 10005;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const double EPS = 1e-9;
const double PI = 3.1415926535;

int dp[MAXN][MAXD];

int add(const int& a, const int& b) {
    if(a + b >= MOD)
        return (a + b - MOD);
    return (a + b);
}

int subt(const int& a, const int& b) {
    if(a - b < 0)
        return (a - b + MOD);
    return (a - b);
}

int main() {
    int D, ans;
    string K;

    cin >> K >> D;
    int sz = K.size();

    for(int i = 0; i <= K[0] - '0' - 1; i++)
        dp[0][i % D] += 1;                         
    int sum_of_max = (K[0] - '0') % D;        
  
    for(int i = 0; i < sz - 1; i++) {
        int next_znam = K[i + 1] - '0';
        for(int j = 0; j < D; j++)
            for(int znam = 0; znam <= 9; znam++)
                dp[i + 1][(j + znam) % D] = add(dp[i + 1][(j + znam) % D], dp[i][j]);

        for(int znam = 0; znam <= next_znam - 1; znam++)
            dp[i + 1][(sum_of_max + znam) % D] = add(dp[i + 1][(sum_of_max + znam) % D], 1);
        sum_of_max = (sum_of_max + next_znam) % D;
    }

    if(sum_of_max == 0)                          
        cout << dp[sz - 1][0] << endl;
    else                                            
        cout << subt(dp[sz - 1][0], 1) << endl;

    return 0;
}

