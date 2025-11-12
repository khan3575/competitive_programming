#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<vector<ll>>v;
int n;
vector<vector<ll>>dp;

ll isOK(int n, int op)
{

	if(n<0)
	{
		return 0;
	}

	if(dp[n][op]!=-1)
	{
		return dp[n][op];
	}
	ll mx =0;
	for(int i = 0; i<3; i++)
	{
		if(i==op)
		{
			continue;
		}
		mx = max(mx, isOK(n-1,i)+v[n][i]);
		
	}
	return dp[n][op] = mx;

}

void solve()
{
	cin >> n;
	v.assign(n, vector<ll>(3));
	for(int i = 0; i < n; i++)
	{
		cin >> v[i][0]>> v[i][1] >> v[i][2];
	}
	dp.assign(n, vector<ll>(3,-1));
	ll ans1 = isOK(n-1,0);
	ll ans2 = isOK(n-1,1);
	ll ans3 = isOK(n-1,2);


	ll ans = max(ans2, max(ans1,ans3));
	cout<<ans<<endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t=1;
	//cin >> t;
	while(t--){
		solve();
	}
}