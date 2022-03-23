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

int dp[MAXN];
int a[110];

int main() {
    int N, K;
    cin >> N >> K;

    for(int i = 0; i < N; i++)
        cin >> a[i];


    for(int i = 0; i <= K; i++) {
        for(int j = 0; j < N; j++) {
            if(i + a[j] >= MAXN)
                continue;
            if(dp[i + a[j]] == 1)
                continue;
            dp[i + a[j]] = 1 - dp[i];
        }
    }

    if(dp[K] == 1)
        cout << "First" << endl;
    else
        cout << "Second" << endl;

    return 0;
}
