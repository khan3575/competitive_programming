#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n, k;
vector<ll>v;
vector<ll>dp;

ll isOK(int x)
{
	if(x==0)
	{
		return 0;
	}
	if(dp[x]!=-1)
	{
		return dp[x];
	}
	ll ans = INT_MAX;
	for(int i = 1; i<=k; i++)
	{
		if(x-i>=0)
		{
			ans = min(ans, isOK(x-i) + abs(v[x]-v[x-i]));
		}
	}
	return dp[x] = ans;
}

void solve()
{
	cin >> n >> k;
	v.resize(n);
	dp.assign(n,-1);
	for(auto &i : v) cin >> i;
	
	ll ans = isOK(n-1);
	cout<< ans<<endl;
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