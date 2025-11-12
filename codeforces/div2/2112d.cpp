#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<vector<int>>adj;

vector<bool>vis;
vector<pair<int,int>>ans;
void dfs(int node, int parent, bool parity)
{
	if(vis[node])
	{
		return;
	}
	vis[node] = true;

	for(int child : adj[node])
	{
		if(child== parent || vis[child])
		{
			continue;
		}
		if(parity == 0)
		{
			ans.push_back({node,child});
		}
		else{
			ans.push_back({child,node});
		}
		dfs(child, node, !parity);
	}
}


void solve()
{
	int n;
	cin >> n;
	adj.assign(n+1, vector<int>());

	vector<int> indeg, outdeg;
	indeg.assign(n+1,0);
	outdeg.assign(n+1,0);
	vis.assign(n+1, 0);
	for(int i = 0; i < n-1; i++)
	{
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		indeg[x]++;
		outdeg[x]++;
		indeg[y]++;
		outdeg[y]++;
	}
	bool ok=false;
	int root =-1;
	for(int i = 1; i<=n;i++)
	{
		if(outdeg[i]>=2)
		{
			ok= true;
			root=i;
			break;
		}
	}
	if(!ok)
	{
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	vis[root]=true;
	int child1 = adj[root][0];
	int child2 = adj[root][1];
	dfs(child1, root, 0);
	for(int i = 1; i<adj[root].size(); i++)
	{
		dfs(adj[root][i], root, 1);
		ans.push_back({root,adj[root][i]});
	}
	ans.push_back({child1,root});
	for(auto i: ans)
	{
		cout<< i.first<<" "<<i.second<<endl;
	}
	//cout<<endl;
	ans.clear();
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t=1;
	cin >> t;
	while(t--){
		solve();
	}
}