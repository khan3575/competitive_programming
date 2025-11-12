#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


void solve()
{
	int n, k;
	cin >> n >> k;
	vector<ll>v(n), dp;
	for(int i = 0; i< n; i++)
	{
		cin >>v[i];
	}
	dp.assign(n,-1);
	ll final_ans=0;
	dp[0]=0;
	for(int i = 1; i<n; i++)
	{
		ll ans = INT_MAX;
		for(int j = 1; j<=k; j++)
		{
			if(i-j>=0)
			{
				ans = min(ans, dp[i-j]+ abs(v[i]-v[i-j]));
				//cout<< v[i]-v[i-j]<< " i "<<(i-j)<<" | " ;
			}
		}
	// /	cout<<endl	;
		dp[i]= ans;
	}
	cout<<dp[n-1]<<endl;
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