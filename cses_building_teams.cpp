#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl

//------------------------------------------------------------
vector<int> graph[100000];
vector<int> color(100000, -1);
int n, m;

bool bipartite(int node){
    queue<int> q;
    q.push(node);
    color[node] = 1;

    while (q.size()){
        int u = q.front(); q.pop();
        for (auto v: graph[u]){
            if (color[v] == -1){
                color[v] = 1- color[u];
                q.push(v);
            }

            else if (color[v] == color[u]) return false;
        }
    }

    return true;
}

void solve(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }

    for (int i=0; i<n; ++i){
        if (color[i] != -1) continue;
        if (bipartite(i) == false){
            cout << "IMPOSSIBLE";
            return;
        }
    }

    for (int i=0; i<n; ++i){
        if (color[i] == 0) cout << 2 << ' ';
        else cout << 1 << ' ';
    }

}

// ------------------------------------------------------------

int32_t main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t = 1;
    // cin >> t;

    while (t--){
        solve();
    }
}
