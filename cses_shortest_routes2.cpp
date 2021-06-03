#include<bits/stdc++.h>
using namespace std;
#define int long long
#define deb(x) cout << #x << "=" << x << endl
const int inf = 1e15;

//------------------------------------------------------------
int dp[500][500];
int n, m, q;

void floydWarshall(){

    for (int k=0; k<n; ++k){
        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j){
                if (dp[i][k] < inf and dp[k][j] < inf){
                    dp[i][j] = min(dp[i][j], dp[i][k]+ dp[k][j]);
                }
            }
        }
    }

}

void solve(){
    cin >> n >> m >> q;

    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            dp[i][j] = inf;
        }
        dp[i][i] = 0;
    }

    for (int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        dp[a][b] = min(dp[a][b], c);
        dp[b][a] = min(dp[b][a], c);
    }

    floydWarshall();

    while (q--){
        int a, b;
        cin >> a >> b;
        int ans = dp[--a][--b];
        if (ans == inf) ans = -1;
        cout << ans << '\n';
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
