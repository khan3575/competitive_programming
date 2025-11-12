#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n';
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)

vector<vector<int>>adj;
vector<int> team;
bool isBipartait= true;

void dfs(int cur, int parent)
{
	if(team[cur]!=0)
	{
		return;
	}
	if(!isBipartait)
	{
		return;
	}
	int choise = (team[parent]== 1)? 2: 1;
	team[cur] = choise;
	for(auto child : adj[cur])
	{
		if(child== parent){
			continue;
		}
		if(team[child]==choise)
		{
			isBipartait= false;
			return;
		}
		dfs(child,cur);
		
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;
	adj.assign(n+3,vector<int>());
	team.assign(n+3,0);
	for(int i = 0; i<m; i++)
	{
		int x , y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	team[0] = 2;
	for(int i = 1; i<=n; i++)
	{
		if(team[i]==0)
		{
			dfs(i,0);	
		}
	}
	if(!isBipartait)
	{
		cout<<"IMPOSSIBLE\n";
		return;
	}
	for(int i = 1; i<=n; i++)
	{
		cout<<team[i]<<" ";
	}
	cout<<endl;

}


int main()
{
	
	unsyncIO;
	int t=1;
	// cin >> t; 
	while(t--){
		solve();
	}
}