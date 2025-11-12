#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n';
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)

vector<vector<int>>adj;
vector<bool>vis;
vector<int> parent;
int n, m;
void bfs(int cur)
{
	queue<int>q;
	q.push(cur);
	vis[cur]=true;
	while(!q.empty())
	{
		
		int node = q.front();
		q.pop();
		
		if(node == n)
		{
			vis[node]=true;
			break;
		}
		for(auto child : adj[node])
		{
			if(vis[child])
			{
				continue;
			}
			vis[child]=true;
			parent[child]=node;
			q.push(child);
		}
	}
}

void solve()
{
	cin >> n >> m;
	adj.assign(n+2, vector<int>());
	vis.assign(n+2,0);
	parent.assign(n+2,-1);

	for(int i = 0; i<m ; i++)
	{
		int y,x;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	bfs(1);
	parent[1]=-1;
	if(vis[n])
	{
		vector<int> path;
		int x = n;
		while(x!=-1)
		{
			path.push_back(x);
			x = parent[x];
		}
		reverse(path.begin(),path.end());
		cout<<path.size()<<endl;
		for(auto i: path)
		{
			cout<<i<<" ";
		}
	}
	else{
		cout<<"IMPOSSIBLE\n";
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