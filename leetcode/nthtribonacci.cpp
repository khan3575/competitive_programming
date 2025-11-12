#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


void solve()
{
	ll n;
	cin >> n;
	ll dp [n+2]={0};
	dp[0]=0;
	dp[1]=1;
	dp[2]=1;
	for(int i = 3; i<=n; i++)
	{
		dp[i] = dp[i-1]+ dp[i-2]+ dp[i-3];
	}
	cout<<dp[n]<<endl;
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