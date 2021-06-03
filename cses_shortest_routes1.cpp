#include<bits/stdc++.h>
using namespace std;
#define int long long
#define deb(x) cout << #x << "=" << x << endl
#define all(x) x.begin(), x.end()
#define F first
#define S second
typedef pair<int, int>	PII;

//------------------------------------------------------------
vector<PII> graph[100000];
vector<int> dist(100000, LLONG_MAX);
int n, m;

void dijkstra(){
    dist[0] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0,0});

    while(pq.size()){
        int v = pq.top().S;
        int d_v = pq.top().F;
        pq.pop();

        if (d_v != dist[v]) continue;

        for (auto edge: graph[v]){
            int to = edge.F;
            int weight = edge.S;

            if (dist[v]+ weight < dist[to]){
                dist[to] = dist[v]+ weight;
                pq.push({dist[to], to});
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    for (int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        graph[--a].push_back({--b, c});
    }

    dijkstra();

    for (int i=0; i<n; ++i){
        cout << dist[i] << ' ';
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
