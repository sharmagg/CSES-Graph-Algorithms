#include<bits/stdc++.h>
using namespace std;
#define int         long long
#define deb(x)      cout << #x << "=" << x << endl
#define deb2(x,y)   cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define all(x)      x.begin(), x.end()
#define F           first
#define S           second

typedef pair<int, int>  pii;
const int mod = 1e9 + 7, inf = 1e15;

//___________________________________________________________________________
int n, m;
vector<int> graph[100000];
vector<int> graph2[100000];
bool vis[100000];

void dfs(int u){
	vis[u] = true;
	for (auto v: graph[u]){
		if (vis[v]) continue;
		dfs(v);
	}
}

void dfs2(int u){
	vis[u] = true;
	for (auto v: graph2[u]){
		if (vis[v]) continue;
		dfs2(v);
	}
}

void solve(){
    cin >> n >> m;
    
    for (int i=0; i<m; ++i){
    	int u, v;
    	cin >> u >> v;
    	--u; --v;
    	graph[u].push_back(v);
    	graph2[v].push_back(u);
    }

    dfs(0);
    for (int i=0; i<n; ++i){
    	if (!vis[i]){
    		cout << "NO\n";
    		cout << 1 << ' ' << i+1;
    		return;
    	}
    }

    memset(vis, false, sizeof(vis));
    dfs2(0);
    for (int i=0; i<n; ++i){
    	if (!vis[i]){
    		cout << "NO\n";
    		cout << i+1 << ' ' << 1;
    		return;
    	}
    }

    cout << "YES\n";
}

//___________________________________________________________________________

signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int TC = 1;
    // cin >> TC;

    while (TC--){
        solve();
    }
}
