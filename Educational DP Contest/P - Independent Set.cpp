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

vector <int> G[MAXN];
bool visited[MAXN];
ll black[MAXN];
ll white[MAXN];

ll add(ll a, ll b) {
    return (a + b) % MOD;
}

ll mult(ll a, ll b) {
    return (a * b) % MOD;
}

void preprocess() {
    for(int i = 0; i < MAXN; i++) {
        black[i] = 1;
        white[i] = 1;
    }
}

void dfs(int curr) {
    visited[curr] = true;
    for(auto v : G[curr]) {
        if(visited[v] == false) {
            dfs(v);
            black[curr] = mult(black[curr], white[v]);
            white[curr] = mult(white[curr], add(white[v], black[v]));
        }
    }
}

int main() {
    int N, u, v;
    int root = 0;

    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        u --; v --;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    preprocess();
    dfs(root);

    cout << add(black[root], white[root]) << endl;

    return 0;
}

