#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n';
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
vector<vector<int>>adj;
vector<int>vis;
int start_i=-1, end_i=-1;
bool circleFound=false;
vector<int>parent;
bool dfs(int node, int par)
{
	vis[node]=1;

	for(int child : adj[node])
	{
		
		parent[child]= node;
		if(vis[child]==0)
		{
			if(dfs(child,node)){
				return true;
			}
		}
		else if(vis[child]==1)
		{
			start_i = child;
			end_i = node;
			return true;
		}

	}
	vis[node]=2;
	return false;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	adj.assign(n+1, vector<int>());
	vis.assign(n+1, 0);
	parent.assign(n+1,-1);
	for(int i = 0; i< m; i++)
	{
		int x, y;
		cin>> x >> y;
		adj[x].push_back(y);
	}

	for(int i =  1; i<=n;i++)
	{
		if(vis[i]==0 && dfs(i,0))
		{
			circleFound=true;
			break;			
		}
	}
	if(!circleFound)
	{
		cout<<"IMPOSSIBLE\n";
		return;
	}
	vector<int>path;
	int cur = end_i;
	while(cur != start_i)
	{
		path.push_back(cur);
		cur = parent[cur];
	}

	path.push_back(start_i);
	reverse(path.begin(),path.end());
	path.push_back(start_i);

	cout<<path.size()<<endl;
	for(auto i: path)
	{
		cout<<i<<" ";
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