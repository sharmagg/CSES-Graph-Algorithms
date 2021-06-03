#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl
#define all(x) x.begin(), x.end()
#define F first
#define S second
typedef pair<int, int>  PII;

//------------------------------------------------------------
vector<int> graph[100000];
int order[100000] = {0}, indegree[100000] = {0};
int n, m;

bool topsort(){
    for (int u=0; u<n; ++u){
        for (auto v: graph[u]){
            indegree[v]++;
        }
    }

    queue<int> q;
    for (int i=0; i<n; ++i){
        if (indegree[i] == 0) q.push(i);
    }
    int index = 0;

    while (q.size()){
        int u = q.front(); q.pop();
        order[index++] = u;

        for (auto v: graph[u]){
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }

    if (index != n) return false;
    return true;
}

void solve(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
    }

    if (topsort()){
        for (int i=0; i<n; ++i){
            cout << order[i]+ 1 << ' ';
        }
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
