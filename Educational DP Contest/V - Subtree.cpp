#include <bits/stdc++.h>

#define black first
#define white second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

const int MAXN = 1e5 + 500;

int MOD;
vector <int> G[MAXN];
vector <int> tree[MAXN];
vector <int> prefix[MAXN];
vector <int> sufix[MAXN];
int down[MAXN], up[MAXN];

int add(const int& a, const int& b) {
    if(a + b >= MOD)
        return (a + b - MOD);
    return (a + b);
}

int mult(const int& a, const int& b) {
    return (((ll)a * b) % MOD);
}

void dfs(int node, int parent = -1) {
    for(auto child : G[node]) {
        if(child != parent) {
            tree[node].push_back(child);
            dfs(child, node);
        }
    }
}

void solve_down(int node) {
    int sz = tree[node].size();
    prefix[node].resize(sz);
    sufix[node].resize(sz);

    down[node] = 1;
    for(int i = 0; i < sz; i++) {
        int child = tree[node][i];
        solve_down(child);
        down[node] = mult(down[node], 1 + down[child]);
    }

    for(int i = 0; i < sz; i++) {
        int child = tree[node][i];
        prefix[node][i] = 1 + down[child];
        if(i == 0)
            continue;
        prefix[node][i] = mult(prefix[node][i], prefix[node][i - 1]);
    }

    for(int i = sz - 1; i >= 0; i--) {
        int child = tree[node][i];
        sufix[node][i] = 1 + down[child];
        if(i == sz - 1)
            continue;
        sufix[node][i] = mult(sufix[node][i], sufix[node][i + 1]);
    }
}

void solve_up(int node) {
    int sz = tree[node].size();
    for(int i = 0; i < sz; i++) {
        int child = tree[node][i];
        up[child] = up[node];
        if(i != 0)
            up[child] = mult(up[child], prefix[node][i - 1]);
        if(i != sz - 1)
            up[child] = mult(up[child], sufix[node][i + 1]);
        up[child] = add(up[child], 1);
        solve_up(child);
    }
}

int main() {
    int N, u, v;

    scanf("%d%d", &N, &MOD);
    for(int i = 0; i < N - 1; i++) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }


    dfs(1);
    solve_down(1);
    up[1] = 1;
    solve_up(1);

    for(int i = 1; i <= N; i++) {
        printf("%d\n", mult(down[i], up[i]));
    }

    return 0;
}
