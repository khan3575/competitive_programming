#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
char dir[]={'U','D','L','R'};

int n, m;
pair<int,int> s;
pair<int,int> d;
vector<vector<bool>>vis;
vector<vector<char>>v;
bool found = false;
vector<vector<pair<int,int>>>parent;
vector<vector<char>> how;

void bfs(pair<int,int> a)
{
	queue<pair<int,int>>q;
	q.push(a);
	vis[a.first][a.second]= true;
	while(!q.empty())
	{
		pair<int,int> b = q.front();
		q.pop();

		if(b == d)
		{

			vis[b.first][b.second]=true;
			found=true;
			break;
		}
		auto [i,j] = b;
		for(int k = 0; k<4; k++)
		{
			int ix = i+dx[k];
			int jx = j+ dy[k];
			if((ix>=0 && ix<n && jx >=0 && jx< m) && (v[ix][jx]=='.') && vis[ix][jx]==false)
			{
				vis[ix][jx]=true;
				parent[ix][jx] = b;
				how[ix][jx] = dir[k];
				q.push({ix, jx});
			}

		}
	}

}

void solve()
{
	cin >> n >> m;

	v.resize(n,vector<char>(m));
	vis.resize(n,vector<bool>(m,false));
	parent.resize(n,vector<pair<int,int>>(m,{-1,-1}));
	how.resize(n,vector<char>(m,'_'));

	for(int i = 0; i< n;i++)
	{
		for(int j = 0; j< m; j++)
		{
			cin>>v[i][j];
			if(v[i][j]=='A')
			{
				v[i][j]='.';
				s = {i,j};
			}	
			if(v[i][j]=='B')
			{
				v[i][j]='.';

				d = {i,j};
			}
		}
	}
	parent[s.first][s.second] = {-1,-1};
	bfs(s);

	if(!found){
		cout<<"NO\n";
		return ;
	}
	string path;
	pair<int,int> x = d;
	while(x != s)
	{
		char ch = how[x.first][x.second];
		path.push_back(ch);
		x = parent[x.first][x.second];
	}

	reverse(path.begin(),path.end());
	cout<<"YES\n";
	cout<<path.size()<<endl;
	cout<<path<<endl;
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