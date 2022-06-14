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
class UnionFind{
private:
	vector<int> root;
	vector<int> rank;
	int comp;
	int mxsize;

public:	
	UnionFind(int sz): root(sz+1), rank(sz+1), comp(sz), mxsize(1){
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
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (rank[x] < rank[y]) swap(x, y);
		
		root[y] = x;
		rank[x] += rank[y];
		mxsize = max({mxsize, rank[x]});
		comp--;
	}

	int components(){
		return comp;
	}

	int max_size(){
		return mxsize;
	}
};

void solve(){
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    
    while (m--){
    	int u, v;
    	cin >> u >> v;
    	uf.unionset(u, v);
    	cout << uf.components() << ' ' << uf.max_size() << '\n';
    }

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
