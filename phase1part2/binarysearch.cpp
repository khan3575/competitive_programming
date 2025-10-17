#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll>v,a;
ll n, k;

bool isOk(ll i, ll x)
{
	if(v[i]<=x)
	{
		return true;
	}
	else{
		return false;
	}
}
ll binary2(ll y)
{
	ll ans  =-1;
	ll l =0, r= n-1;
	while(l<=r)
	{
		ll mid = l + (r-l)/2;
		if(isOk(mid,y))
		{
			ans= mid;
			l =  mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	return ans+1;
}


ll binary(ll x)
{
	ll cnt = 0;
	for(int i = 0; i < n; i++)
	{
		
		cnt += binary2(x-a[i]);
	}
	return cnt;
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

	ll l = 0 , r= INT_MAX;
	ll ans=-1;
	while(l<=r)
	{
		ll mid =  l + (r - l) / 2;

		if(binary(mid)<=k)
		{
			
			l = mid + 1;
		}
		else{
			ans= mid;
			r  = mid - 1;
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