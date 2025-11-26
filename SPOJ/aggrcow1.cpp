#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)


void solve()
{
	int n, k;
	cin >> n >> k;
	vector<ll>v(n);
	for(auto &i: v) cin >> i;

	sort(v.begin(),v.end());

	auto check = [&](ll x)->bool{
	
		ll cnt=1;
		ll last =v[0];
		for(int i = 1; i< n; i++)
		{
			if(v[i]-last >=x )
			{
				cnt++;
				last = v[i];
				if(cnt>=k)
				{
					return true;
				}
			}
		}

		return cnt>=k;

	};
	
	ll l = 0, r = 1e17;
	while(l<=r)
	{
		ll mid = l+ (r-l)/2;

		if(check(mid))
		{
			l = mid + 1;
		}
		else{
			r = mid -1;
		}
	}
	cout<< r<<endl;
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