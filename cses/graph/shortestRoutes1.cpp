#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n';
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
const ll INF = 1e18;
vector<vector<pair<ll,ll>>>adj;
vector<ll>dist;
int n, m;


void solve()
{
	cin >> n >> m;
	adj.assign(n+1, vector<pair<ll,ll>>());
	dist.assign(n+1, INF);
	for(int i = 0; i< m; i++)
	{
		int x, y, w;
		cin >> x >> y>> w;
		adj[x].push_back({y,w});
	}
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
	dist[1]=0;
	pq.push({0,1});
	while(!pq.empty())
	{
		auto [d, u] = pq.top();
		pq.pop();
		if(d>dist[u])
		{
			continue;
		}
		for(auto child: adj[u])
		{
			auto [v, w] = child;
			if(dist[u]+w < dist[v])
			{
				dist[v] = dist[u]+w;
				pq.push({dist[v],v});
			}
		}

	}
	for(int i = 1; i<=n ; i++)
	{
		cout<<dist[i]<<" ";
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