#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)


void solve()
{
	ll n, k;
	cin >> n >> k;

	ll l = 1, r= 1e18;

	auto can = [&](ll mid) ->bool{
		ll divByN = mid / n;
		ll remain = mid - divByN;

		return remain >=k;
	};

	while(l<=r)
	{
		ll mid = l + (r-l)/2;
		if(can(mid))
		{
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	cout<<l<<endl;
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