#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll>v,a;
ll n, k;

bool binary(ll x)
{
	ll ans= 0;
	for(int i =  0; i < n; i++)
	{
		ll rem = x - a[i];

		ll up = upper_bound(v.begin(),v.end(), rem)-v.begin();
		

		ans += up;
		if(ans>=k)
		{
			break;	
		}
	}
	return ans>=k;
}


void solve()
{
	cin >> n>> k;
	v.resize(n);
	a.resize(n);
	for(int i = 0; i < n;i++)
	{
		cin >> v[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(v.begin(),v.end());
	sort(a.begin(),a.end());

	ll l = 0 , r= 1e13;
	ll ans=-1;
	while(l<=r)
	{
		ll mid =  l + (r - l) / 2;

		if(binary(mid))
		{
			r = mid-1;
			ans= r;
		}
		else{
			l = mid + 1;
		}
	}
	cout<< l<<'\n';
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