#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)

const int MXN = 10005;
vector<vector<int>>adj;
map<string,int> element_map;
vector<bool> vis;
vector<int> exit_order;
vector<int> root;
vector<vector<int>>adj_scc;
vector<vector<int>>adj_rev;
bitset<MXN> reachable[MXN];



int scc_count=1;
void dfs(int node)
{
	vis[node] = true;

	for(auto child : adj[node])
	{
		if(!vis[child])
		{
			dfs(child);
		}
	}
	exit_order.push_back(node); // storing exit order

}


void dfs2(int node)
{
	vis[node]=true;
	root[node]=scc_count;  // point to the codensed graph's node.
	for(auto child: adj_rev[node])
	{
		if(!vis[child])
		{
			dfs2(child);
		}
	}
}

int bfs(int s, int d)
{
	if(s == d)
	{
		return 0;
	}
	vector<int>dist(n+1,0);
	vector<bool>visited(n+1,0);
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int child : adj[u])
		{
			if(!visited[child])
			{
				
			}
		}

	}
}


void solve()
{
	int n;
	cin >> n;
	
	string s;
	//giving every unique string an id
	for(int i = 1; i <=n; i++)  
	{
		cin >> s;
		element_map[s] = i;
	}


	// n+1 for 1 based indexing in graphs
	adj.assign(n+1, vector<int>());
	int m;
	cin >> m;
	
	//creating the adjacency list 
	string t;
	for(int i = 0; i< m; i++)
	{
		cin >> s >> t;
		int u = element_map[s];
		int v = element_map[t];
		adj[u].push_back(v);// connecting edge u -> v
	}


	int q;
	cin >> q;
	vector<pair<string,string>> que; //storing queries

	while(q--)
	{
		cin >> s >> t;
		que.push_back({s,t});
	}


	// Graph compression 
	// creating the nodes list in increasing order based on exit-time
	vis.assign(n+1,false);
	for(int i = 1; i<=n ; i++) // O(n)
	{
		if(!vis[i]) 
		{
			dfs(i);
		}
	}


	//creating transpose graph
	adj_rev.assign(n+1, vector<int>());

	for(int node= 1; node<= n; node++)
	{
		for(auto child : adj[node])
		{
			adj_rev[child].push_back(node); // reversing the edge direction u-> v to v -> u
		}
	}

	reverse(exit_order.begin(), exit_order.end());
	//creating couting scc 


	vis.assign(n+1, false);
	root.assign(n+1, -1);
	scc_count = 1;
	for(auto x: exit_order)
	{
		if(!vis[x])
		{
			dfs2(x);
			scc_count++;
		}
	}

	//building the condense graph
	// used set to avoid duplicates.
	vector<set<int>> scc_set(scc_count+1); // scc_count+1 is for 1 based indexing
	for(int node = 1; node<= n; node++)
	{
		int u = root[node];
		for(int child: adj[node])
		{
			
			int v  = root[child];
			if(v!=u)
			{
				scc_set[u].insert(v);
			}
		}
	}

	// making the scc adjacency list
	adj_scc.assign((int)scc_set.size()+1, vector<int>());
	for(int i = 1; i <=scc_count; i++)
	{
		for(auto j : scc_set[i])
		{
			adj_scc[i].push_back(j);
		}
	}


	// precomputing the reachability using the bitset dp 
	for(int i = scc_count ; i>=1; i--)
	{
		reachable[i]= 0;
		reachable[i][i] = 1;
		for(int v : adj_scc[i])
		{
			reachable[i] |= reachable[v];
		}
	}

	// taking quries and answering solution in o(1)

	for( auto [s,t] : que)
	{
		if(element_map.find(s)==element_map.end() || element_map.find(t) == element_map.end())
		{ 
			cout<<"No\n";
			continue;
		}
		int u = element_map[s];
		int v = element_map[t];

		int u_root =  root[u];
		int v_root = root[v];

		if(reachable[u_root][v_root])
		{
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
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