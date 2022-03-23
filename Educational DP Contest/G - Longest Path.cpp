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

int dist[MAXN];
bool visited[MAXN];
vector <int> G[MAXN];

void preprocess() {
    memset(visited, false, sizeof(visited));
    memset(dist, 0, sizeof(dist));
}

void dfs(int curr) {
    visited[curr] = true;
    for(auto v : G[curr]) {
        if(!visited[v])
            dfs(v);
        dist[curr] = max(dist[curr], dist[v] + 1);
    }
}

int main() {
    preprocess();
    int N, M, u, v, ans = 0;

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> u >> v;
        G[u].push_back(v);
    }

    for(int i = 1; i <= N; i++)
        if(!visited[i])
            dfs(i);

    for(int i = 1; i <= N; i++)
        ans = max(ans, dist[i]);
    cout << ans << endl;
    return 0;
}
