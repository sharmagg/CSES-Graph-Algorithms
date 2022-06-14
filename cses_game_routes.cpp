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
vector<int> graph[100005];
int dp[100005];
int indegree[100005];

void solve(){
    int n, m, u, v;
    cin >> n >> m;
    
    memset(dp, 0, sizeof(dp));
    memset(indegree, 0, sizeof(indegree));
  	dp[1] = 1;

    while (m--){
    	cin >> u >> v;
    	graph[u].push_back(v);
    	indegree[v]++;
    }

    // topsort (kahn's algo)
  	queue<int> q;
  	for (int i=1; i<=n; ++i){
  		if (indegree[i] == 0) q.push(i);
  	}

  	while (!q.empty()){
  		int u = q.front();
  		q.pop();
  		for (auto v: graph[u]){
  			dp[v] = (dp[v] + dp[u])%mod;
  			indegree[v]--;
  			if (indegree[v] == 0) q.push(v);
  		}
  	}

    cout << dp[n];
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
