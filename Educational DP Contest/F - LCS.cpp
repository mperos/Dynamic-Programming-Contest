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

const int MAXN = 3100;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const double EPS = 1e-9;
const double PI = 3.1415926535;

string s, t;
int dp[MAXN][MAXN];

string backtrack() {
    int i = s.size();
    int j = t.size();
    string ans = "";

    while(i != 0 && j != 0) {
        if(s[i - 1] == t[j - 1]) {
            ans += s[i - 1];
            i --; j --;
        }
        else if(dp[i][j] == dp[i - 1][j])
            i --;
        else if(dp[i][j] == dp[i][j - 1])
            j --;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int sz, tz;

    cin >> s >> t;
    sz = s.size();
    tz = t.size();

    for(int i = 1; i <= sz; i++) {
        for(int j = 1; j <= tz; j++) {
            if(s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << backtrack() << endl;
    return 0;
}
