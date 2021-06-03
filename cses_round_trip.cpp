#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl
#define all(x) x.begin(), x.end()
#define F first
#define S second
typedef pair<int, int>  PII;

//------------------------------------------------------------
vector<int> graph[100000];
vector<int> P(100000, -1);
bool visited[100000];
int n, m, cycle_start, cycle_end;

bool dfscycle(int u, int p){
    visited[u] = true;

    for (auto v: graph[u]){
        if (v == p) continue;
        if (visited[v]){
            cycle_start = v;
            cycle_end = u;
            return true;
        }

        P[v] = u;
        if (dfscycle(v, u)) return true;
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


    bool ans = false;
    for (int u = 0; u < n; u++) {
        if (!visited[u] and dfscycle(u, P[u])){
            ans = true;
            break;
        }
    }
    

    if (ans){
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = P[v]){
            cycle.push_back(v);
        }
        cycle.push_back(cycle_start);

        reverse(all(cycle));
        cout << cycle.size() << '\n';
        for (auto c: cycle) cout << c+ 1 << ' ';
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
