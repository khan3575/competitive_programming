#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n';



void solve()
{
	int n;
	cin >> n;
	vector<ll>v(n);
	for(int i = 0; i <n; i++)
	{
		cin >>v[i];
	}
	map<ll,ll> memo;
	memo[0]=0;
	for(int i =1; i< n; i++)
	{
		ll x = abs(v[i]-v[i-1]) + memo[i-1];
		ll y = INT_MAX;
		if(i>1)
		{
			y =  abs(v[i]-v[i-2]) + memo[i-2];  
		}
		//cout<<memo[i]<<" "<<min(y,x)<<endl;
		memo[i] = min(y,x);
	}
	cout<<memo[n-1]<<endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t=1;
	// cin >> t;
	while(t--){
		solve();
	}
}