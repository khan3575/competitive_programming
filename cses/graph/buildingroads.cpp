#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)

vector<vector<int>>adj;
vector<bool> vis;

void dfs(int cur, int parent)
{
	if(vis[cur])
	{
		return;
	}
	vis[cur]=true;
	for(auto child : adj[cur])
	{
		if(child==parent)
		{
			continue;
		}
		dfs(child,cur);
	}
}
void solve()
{
	int n, m;
	cin >> n >> m;
	adj.resize(n+1);
	vis.assign(n,0);

	for(int i = 0; i< m; i++)
	{
		int x, y;
		cin >> x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	vector<int>connected_leader;
	for(int i = 1; i<=n; i++)
	{
		if(vis[i]==false)
		{
			dfs(i,-1);
			connected_leader.push_back(i);
		}
	}

	cout<<(int)connected_leader.size()-1<<endl;
	for(int i = 0; i<(int)connected_leader.size()-1; i++)
	{
		cout<< connected_leader[i] <<" "<< connected_leader[i+1]<<" ";
	}
	cout<<endl;

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