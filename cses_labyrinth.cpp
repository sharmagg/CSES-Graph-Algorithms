#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl
#define F first
#define S second
#define all(x) x.begin(), x.end()
typedef pair<int, int>	PII;

//------------------------------------------------------------
int n, m, erow, ecol;
char A[1000][1000];
bool visited[1000][1000];
int previous[1000][1000];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
string stepDir = "URDL";

bool bfs(int i, int j){
    queue<int> rq, cq;
    rq.push(i); cq.push(j);
    visited[i][j] = true;

    while (rq.size()){
        int r = rq.front(); rq.pop();
        int c = cq.front(); cq.pop();

        for (int k = 0; k < 4; ++k){
            int row = r + dr[k];
            int col = c + dc[k];
            if (row < 0 or col < 0 or row > n-1 or col > m-1) continue;
            if (A[row][col] == '#' or visited[row][col]) continue;

            visited[row][col] = true;
            previous[row][col] = k;
            rq.push(row); cq.push(col);

            if (row == erow and col == ecol) return true;
        }
    }

    return false;
}

void solve() {
    cin >> n >> m;
    int srow, scol;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            if (A[i][j] == 'A') {
                srow = i; scol = j;
            } 
            if (A[i][j] == 'B') {
                erow = i; ecol = j;
            }
        }
    }

    if (bfs(srow, scol)){
        cout << "YES\n";
        vector<int> path;
        int row = erow, col = ecol;
        while (row != srow or col != scol){
            int k = previous[row][col];
            path.push_back(k);
            row -= dr[k];
            col -= dc[k];
        }

        reverse(all(path));
        cout << path.size() << '\n';
        for (auto p: path) cout << stepDir[p];
        cout << endl;
    }

    else cout << "NO\n";

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
