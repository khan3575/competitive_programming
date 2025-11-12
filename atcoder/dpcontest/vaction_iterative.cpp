#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


void solve()
{
	int n;
	cin >> n;
	vector<ll>a(n),b(n),c(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i]>> b[i] >> c[i];
	}
	vector<vector<ll>> dp(n,vector<ll>(3));
	dp[0][0]=a[0];
	dp[0][1]=b[0];
	dp[0][2]=c[0];

	for(int i = 1; i<n; i++)
	{
		dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = b[i] + max(dp[i-1][2], dp[i-1][0]);
		dp[i][2] = c[i] + max(dp[i-1][1], dp[i-1][0]);
	}
	ll ans = 0;
	for(int i = 0; i<3;i++)
	{
		ans = max(ans, dp[n-1][i]);
	}
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