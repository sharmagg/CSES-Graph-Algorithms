#include<bits/stdc++.h>
using namespace std;
#define int long long
#define deb(x) cout << #x << "=" << x << endl

//------------------------------------------------------------
int n, m;
int graph[1002][1002];

void dfs(int row, int col){
    if (row < 0 or col < 0 or row > n-1 or col > m-1) return;
    if (graph[row][col] == 1) return;

    graph[row][col] = 1;

    dfs(row+1, col);
    dfs(row-1, col);
    dfs(row, col+1);
    dfs(row, col-1);
}

void solve(){
    cin >> n >> m;

    for (int i=0; i<n; ++i){
        string s;
        cin >> s;
        for (int j=0; j<m; ++j){
            if (s[j] == '.') graph[i][j] = 0;
            else graph[i][j] = 1;
        }
    }

    int ans = 0;
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if (graph[i][j] == 0){
                dfs(i, j);
                ans++;
            }
        }
    }

    cout << ans << '\n';
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
