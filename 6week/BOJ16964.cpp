#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> adj;
vector<int> seq, order, ans;
vector<bool> visited;

// DFS (재귀)
void dfs(int u) {
    visited[u] = true;
    ans.push_back(u);
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    adj.assign(N+1, {});

    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    seq.resize(N);
    order.assign(N+1, 0);
    for (int i = 0; i < N; i++) {
        cin >> seq[i];
        order[seq[i]] = i;
    }

    if (seq[0] != 1) {
        cout << 0;
        return 0;
    }

    for (int u = 1; u <= N; u++) {
        sort(adj[u].begin(), adj[u].end(),
             [&](int a, int b) {
                 return order[a] < order[b];
             });
    }

    visited.assign(N+1, false);
    dfs(1);

    if (ans == seq) cout << 1;
    else           cout << 0;

    return 0;
}
