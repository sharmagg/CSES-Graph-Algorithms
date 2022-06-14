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

struct Edge{
	int u, v, weight;
	bool operator<(Edge const& other){
		return weight < other.weight;
	}
};

class UnionFind{
private:
	vector<int> root;
	vector<int> rank;

public:	
	UnionFind(int sz): root(sz+1), rank(sz+1){
		for (int i=1; i<=sz; ++i){
	    	rank[i] = 1;
	    	root[i] = i;
	    }
	}

	int find(int x){
		if (root[x] == x) return x;
		return root[x] = find(root[x]);
	}

	void unionset(int x, int y){
		int rootx = find(x);
		int rooty = find(y);
		if (rootx == rooty) return;

		if (rank[rootx] > rank[rooty]){
			root[rooty] = rootx;
		}
		else if (rank[rootx] < rank[rooty]){
			root[rootx] = rooty;
		}
		else {
			root[rooty] = rootx;
			rank[rootx]++;
		}
		
	}

	bool connected(int x, int y){
		return find(x) == find(y);
	}
};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    
    while (m--){
    	Edge e;
    	cin >> e.u >> e.v >> e.weight;
    	edges.push_back(e);
    }

    int ans = 0, counter = 0;
    sort(all(edges));
    UnionFind uf(n);

    for (auto e: edges){
    	if (!uf.connected(e.u, e.v)){
    		uf.unionset(e.u, e.v);
    		ans += e.weight;
    		counter++;
    	}
    	if (counter > n-1) break;
    }

    if (counter >= n-1) cout << ans << '\n';
    else cout << "IMPOSSIBLE\n";

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
