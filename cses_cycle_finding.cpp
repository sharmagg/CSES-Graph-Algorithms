#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

//------------------------------------------------------------
int n, m, x;
vector<vector<int>> graph;
vector<int> dist(2501);
vector<int> P(2501, -1);

void BellmanFord(){

    for (int i=0; i<n; ++i){
        x = -1;
        for (auto edge: graph){
            int u = edge[0], v = edge[1], cost = edge[2];
            if (dist[u]+ cost < dist[v]){
                dist[v] = dist[u]+ cost;
                P[v] = u;
                x = v;
            }
        }
    }

}

void solve(){
    cin >> n >> m;
    for (int i=0; i<m; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        graph.push_back({u, v, c});
    }

    BellmanFord();

    if (x == -1) cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i=0; i<n; ++i){
            x = P[x];
        }

        vector<int> cycle;
        for (int v = x; ; v = P[v]){
            cycle.push_back(v);
            if (v == x and cycle.size() > 1) break;
        }
        reverse(all(cycle));

        for (auto c: cycle) cout << c << ' ';
    }

}

// ------------------------------------------------------------

signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t = 1;
    // cin >> t;

    while (t--){
        solve();
    }
}
