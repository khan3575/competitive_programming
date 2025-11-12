#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n';
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)

vector<vector<int>>adj;
vector<bool> vis;
vector<int>parent;
int n,m;
int start_i=-1 , end_j=-1;
bool dfs(int node, int par)
{
	vis[node]=true;
	parent[node]=  par;

	for(auto child : adj[node])
	{
		if( child==par)
		{
			continue;
		}
		if(vis[child])
		{
			start_i = child;
			end_j = node;
			return true;
		}
		
		return dfs(child,node);
	}
	return true;
}

void solve()
{
	cin >> n >> m;
	adj.assign(n+1, vector<int>());
	vis.assign(n+1, 0);
	parent.assign(n+1,0);

	for(int i = 0; i<m; i++)
	{
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	bool found =false;
	for(int i = 1; i<=n; i++)
	{
		if(!vis[i] && dfs(i,0))
		{
			found=true;
			break;
		}
	}
	if(!found)
	{
		cout<<"IMPOSSIBLE\n";
	}
	else{
		vector<int>path;
		int cur = end_j;
		while(cur != start_i)
		{
			path.push_back(cur);
			cur = parent[cur];
		}
		path.push_back(start_i);

		reverse(path.begin(),path.end());
		path.push_back(start_i);


		cout<< path.size()<<endl;
		for(auto i : path)
		{
			cout<<i<<" ";
		}
		cout<<endl;
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