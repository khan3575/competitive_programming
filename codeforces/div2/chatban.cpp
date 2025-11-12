#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)


void solve()
{
	ll k, x;
	cin >> k >> x;
	
	if( x >= k*k)
	{
		cout<< (2*k-1)<<endl;
		return;
	}

	ll l = 1, r = (2*k) - 1;

	//lamda function
	auto can = [&](ll mid) ->bool {
		ll total = 0;
		if(mid<=k)
		{
			total = mid *(mid+1) / 2;
		}
		else{
			ll total_all = k*k;
			ll unsent_count = (2*k -1) -mid;
			ll total_unsent = (unsent_count*(unsent_count+1) / 2);
			total = total_all - total_unsent;
		}
		return total>=x;
	};

	ll ans= 0;
	while(l<=r)
	{
		ll mid = l+ (r - l) /2 ;
		if(can(mid))
		{
			r= mid -1;
		}
		else{
			l = mid +1;
		}
	}
	cout<<l<<endl;
}


int main()
{
	
	unsyncIO;
	int test=1;
	cin >> test;
	while(test--){
		solve();
	}
}