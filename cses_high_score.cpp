#include<bits/stdc++.h>
using namespace std;
#define int long long
#define deb(x) cout << #x << "=" << x << endl
#define F first
#define S second
typedef pair<int, int>  PII;
const int inf = 1e15;

//------------------------------------------------------------
int n, m;
vector<PII> graph[2500];
vector<int> g2[2500];
vector<int> dist(2500, inf);
bool cycle = false;
bool visited[2500] = {false};

void dfs(int u){
    visited[u] = true;
    if (dist[u] == -inf){
        cycle = true;
        return;
    }

    for (auto v: g2[u]){
        if (visited[v]) continue;
        dfs(v);
    }
}

void bellmanFord(){
    dist[0] = 0;

    for (int j=0; j < n-1; ++j){
        for (int u=0; u<n; ++u){
            for (auto p: graph[u]){
                int v = p.F, cost = p.S;
                if (dist[u] < inf and dist[v] > dist[u]+ cost){
                    dist[v] = dist[u]+ cost;
                }
            }
        }
    }

    // last iteration to detect negative cycle
    for (int u=0; u<n; ++u){
        for (auto p: graph[u]){
            int v = p.F, cost = p.S;
            if (dist[u] < inf and dist[v] > dist[u]+ cost){
                dist[v] = -inf;
            }
        }
    }
}

void solve(){
    cin >> n >> m;

    for (int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        graph[--a].push_back({--b, -c});
        g2[b].push_back(a);
    }

    bellmanFord();
    // dfs from target node to check if any negative cycle node is reachable
    // graph used was reverse of the original graph
    dfs(n-1);

    if (cycle) cout << -1;
    else cout << -dist[n-1];
}

// ------------------------------------------------------------

signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t = 1;

    while (t--){
        solve();
    }
}
