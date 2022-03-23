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

const int MAXN = 3005;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const double EPS = 1e-9;
const double PI = 3.1415926535;
const int OFF = 1 << 17;

int dp[MAXN][MAXN];
int prefix[MAXN];

int add(const int& a, const int& b) {
    if(a + b >= MOD)
        return (a + b - MOD);
    return (a + b);
}

int subt(const int& a, const int &b) {
    if(a - b < 0)
        return (a - b + MOD);
    return (a - b);
}

int main() {
    int N;
    string s;

    scanf("%d", &N);
    cin >> s;

    dp[0][1] = 1;
    for(int i = 1; i < N; i++) {
        prefix[0] = 0;
        for(int j = 1; j <= i + 1; j++)
            prefix[j] = add(prefix[j - 1], dp[i - 1][j]);

        for(int j = 1; j <= i + 1; j++) {
            if(s[i - 1] == '>')
                dp[i][j] = prefix[j - 1];
            if(s[i - 1] == '<')
                dp[i][j] = subt(prefix[i + 1], prefix[j - 1]);
        }
    }

    int ans = 0;
    for(int i = 0; i <= N; i++)
        ans = add(ans, dp[N - 1][i]);
    printf("%d\n", ans);

    return 0;
}

