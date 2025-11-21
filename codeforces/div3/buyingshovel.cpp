#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)


void solve()
{
	ll n , k;
	cin>> n >> k;
	if(k>=n)
	{
		cout<<1<<endl;
		return;
	}
	ll sq = sqrtl(n);
	ll ans= n;
	for(ll i =  2; i<=sq; i++)
	{
		if(n%i==0)
		{

			ll x = i;
			ll y = n/i;
			if(x<=k )
			{
				ans = min(ans, n/x);
			}
			if(y<=k)
			{
				ans = min(ans, n/y);
			}
		}
	}
	cout<<ans<<endl;
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