#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

	int n, m;

vector<vector<bool>>vis;
vector<vector<char>>v;
// void dfs(int i, int j)
// {
// 	if(i<0 || i>=n  || j<0 || j>=m || vis[i][j] || v[i][j]=='#')
// 	{
// 		return;
// 	}
		
// 		if(v[i][j]=='.')
// 		{
// 			vis[i][j]=true;
// 			for(int k = 0; k<4; k++)
// 			{
// 				dfs(i+dx[k], j+dy[k]);
// 			}
// 		}
// 		return;
// }

void bfs(int i ,int j)
{
	queue<pair<int,int>>q;
	q.push({i,j});
	vis[i][j]=true;
	while(!q.empty())
	{
		pair<int,int>curent = q.front();
		q.pop();
		auto [l,r] = curent;
		for(int k = 0; k<4; k++)
		{
			int ii = l+dx[k];
			int jj = r+ dy[k];
			if(ii>= 0 || ii<n || jj>=0 || jj<m || !vis[ii][jj] && vis[ii][jj]=='.')
			{
				vis[ii][jj] = true;
				q.push({ii,jj});
			}	
		}

	}

}


void solve()
{
	cin >> n >> m;

	v.resize(n,vector<char>(m));
	vis.resize(n,vector<bool>(m,false));
	for(int i = 0; i< n;i++)
	{
		for(int j = 0; j< m; j++)
		{
			cin>>v[i][j];
		}
	}
	int cnt=0;
	for(int i = 0 ; i< n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			if(v[i][j]=='.' && vis[i][j]==false)
			{
				bfs(i,j);
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;

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