#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl
#define all(x) x.begin(), x.end()

//------------------------------------------------------------
vector<int> graph[100000];
bool visited[100000];
vector<int> p(100000);
int n, m;

bool bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    p[u] = -1;

    while (q.size()){
        int node = q.front(); q.pop();
        for (auto v: graph[node]){
            if (visited[v]) continue;
            visited[v] = true;
            q.push(v);
            p[v] = node;

            if (visited[n-1]) return true;
        }
    }

    return false;
}

void solve(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }

    if (bfs(0)){
        vector<int> path;
        for (int v=n-1; v != -1; v = p[v]){
            path.push_back(v);
        }
        reverse(all(path));

        cout << path.size() << '\n';
        for (auto p: path) cout << p+1 << ' ';
        cout << '\n';
    }
    
    else cout << "IMPOSSIBLE\n";
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
