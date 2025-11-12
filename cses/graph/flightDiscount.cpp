#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n';
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
const ll INF = 1e18;
vector<vector<pair<ll,ll>>> adj;
vector<vector<ll>>dist;
ll n, m;


void solve()
{
	cin >> n >> m;
	adj.assign(n+1, vector<pair<ll,ll>>());
	dist.assign(n+1, vector(2,INF));
	for(int i = 0; i<m; i++)
	{
		ll x,y,w;
		cin >> x >>y >> w;
		adj[x].push_back({y,w});
	}
	priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>>pq;
	dist[1][0]=0;
	pq.push({0,1,0});
	while(!pq.empty())
	{
		auto [d , u, state] = pq.top();
		pq.pop();
		if(d > dist[u][state])
		{
			continue;
		}

		for(auto child : adj[u])
		{
			auto [v, w] = child;
			if(state == 0)
			{
				if(d + w <dist[v][0])
				{
					dist[v][0] = d+ w;
					pq.push({dist[v][0],v,0});
				}
				if(d + w/2 < dist[v][1])
				{
					dist[v][1] = d + w/2;
					pq.push({dist[v][1], v,1});
				}
			}
			else{
				if(d + w < dist[v][1])
				{
					dist[v][1] = d + w;
					pq.push({dist[v][1],v,1});
				}

			}
		}
	}
	cout<< min(dist[n][0],dist[n][1])<<endl;
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