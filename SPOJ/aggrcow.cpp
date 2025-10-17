#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, k;
vector<ll>v;

bool isOK(ll x)
{
	int cnt=1;
	int last_pos = v[0];

	for(int i = 1; i<n; i++)
	{
		if(v[i]-last_pos >= x)
		{
			cnt++;
			last_pos=v[i];
		}
	}
	return cnt >= k;
}

void solve()
{
	cin >> n >> k;
	v.resize(n);
	for(int i = 0 ; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(),v.end());
 
	ll l = 0, r= 1e14;
	while(l<=r)
	{
		ll mid = l + (r-l)/2;

		if(isOK(mid))
		{
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	cout<<r<<endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t=1;
	cin >> t;
	while(t--){
		solve();
	}
}