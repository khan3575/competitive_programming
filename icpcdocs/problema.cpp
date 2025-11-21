#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n';
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)


void solve()
{
	int n;
	cin >> n;
	vector<int>v(n);
	for(int i = 0; i< n; i++)
	{
		cin >> v[i];
	}
	int ans = 0;
	int mx = 0;
	for(int i = 0; i< n; i++)
	{
		int x = max(v[i], v[(i+1)%n]);
		ans += x;
		if(mx > x)
		{
			mx = x;
		}
	}
	cout<< ans<<endl;
}


int main()
{
	
	unsyncIO;
	int t=1;
	cin >> t; 
	while(t--){
		solve();
	}
}