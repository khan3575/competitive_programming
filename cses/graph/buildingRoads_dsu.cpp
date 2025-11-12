#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n';
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
struct DSU{
	vector<int> parent;
	vector<int> sz;
	int num_componets;
	DSU(int n)
	{
		parent.resize(n+1);
		iota(parent.begin(),parent.end(),0);
		sz.resize(n+1,1);
		num_componets = n;
	}
	int find(int i)
	{
		if(parent[i]==i)
		{
			return i;
		}
		return parent[i] = find(parent[i]);
	}

	void unite(int u, int v)
	{
		int root_u = find(u);
		int root_v = find(v);
		if(root_u != root_v)
		{
			if(sz[root_u]< sz[root_v])
			{
				swap(root_u,root_v);
			}
			parent[root_v] = root_u;
			sz[root_u] += sz[root_v];
			num_componets--;
		}
	}
};

void solve()
{
	int n , m;
	cin >> n >> m;
	DSU dsu(n);
	for(int i = 0; i < m;i++)
	{
		int u, v;
		cin >> u >> v;
		dsu.unite(u,v);
	}
	cout<<dsu.num_componets-1<<endl;
	set<int>st;
	for(int i= 1; i<=n ;i++)
	{
		st.insert(dsu.find(i));
	}
	vector<int> path;
	for(int i: st)
	{
		path.push_back(i);
	}
	for(int i=1; i<(int)st.size(); i++)
	{
		cout<< path[i] << " "<<path[i-1]<<endl;
	}
}


int main()
{
	
	unsyncIO;
	int t=1;
	//cin >> t; 
	while(t--){
		solve();
	}
}