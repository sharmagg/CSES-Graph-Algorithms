#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl

//------------------------------------------------------------
vector<int> graph[100000];
bool visited[100000];
vector<int> blocks;

void dfs(int node){
    visited[node] = true;

    for (int v: graph[node]){
        if (visited[v] == false) dfs(v);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }


    for (int i=0; i<n; ++i){
        if (visited[i] == false){
            blocks.push_back(i);
            dfs(i);
        }
    }

    if (blocks.size() < 2){
        cout << 0 << endl;
    }

    else {
        cout << blocks.size()-1 << '\n';
        for (int i=0; i < blocks.size() - 1; ++i){
            cout << blocks[i]+ 1 << ' ' << blocks[i+1]+ 1 << '\n';
        }
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
