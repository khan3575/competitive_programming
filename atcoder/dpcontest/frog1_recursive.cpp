#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n;
vector<ll>v;
vector<ll> memo;
ll jumpmf(int i)
{
	if(i<=0)
	{
		return 0;
	}
	if(memo[i]!=-1)
	{
		return memo[i];
	}

	ll x =  jumpmf(i-1) + abs(v[i]-v[i-1]) ;
	ll y = INT_MAX;
	if(i>1)
	{
		y = jumpmf(i-2) + abs(v[i]-v[i-2]);
	}
	return memo[i] = min(x,y);
}

void solve()
{
	cin >> n;
	v.resize(n+1);
	memo.assign(n,-1);

	for(auto &i : v) cin >> i;

	ll ans = jumpmf(n-1);
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