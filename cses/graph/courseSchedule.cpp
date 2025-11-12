#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n';
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)

vector<vector<int>>adj;
vector<int>indeg;


void solve()
{
	int n, m;
	cin >> n >> m;
	adj.assign(n+1,vector<int>());
	indeg.assign(n+1,0);
	for(int i = 0; i < m; i++)
	{
		int x,y;
		cin >> x >>y;
		adj[x].push_back(y);
		indeg[y]++;
	}
	vector<int> top_sorted;
	queue<int> q;
	for(int i = 1; i<=n; i++)
	{
		if(indeg[i]==0)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int a = q.front();
		q.pop();
		top_sorted.push_back(a);
		for(auto child: adj[a])
		{
			--indeg[child];
			if(indeg[child]==0)
			{
				q.push(child);
			}
		}
	}

	if((int)top_sorted.size()!=n)
	{
		cout<<"IMPOSSIBLE\n";
	}
	else{
		for(auto i: top_sorted)
		{
			cout<< i<< " ";
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