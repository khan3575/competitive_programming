#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)


void solve()
{
	ll n, m, k;
	cin >> n >> m >> k;
	if(n>m)
	{
		swap(n,m);
	}
	auto check = [&](ll x)->bool {
		ll position = 0;
		for(ll i = 1; i<=n; i++)
		{
			position+= min(m,x/i);
			if(position>k)
			{
				break;
			}
		}
		return position<k;
	};

	ll l = 1, r= 1e18;
	// check(7);
	while(l<=r)
	{
		ll mid = l + (r-l)/2;
		if(check(mid))
		{
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}	
	cout<< l<<endl;
}


int main()
{
	
	unsyncIO;
	int t=1;
	//cin >> t; 
	while(t--){
		solve();
	}
}