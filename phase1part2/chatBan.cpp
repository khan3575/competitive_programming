#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll n, k;
ll getSum(ll n)
{
	return n*(n+1)/2;
}

bool ok(ll x)
{
	ll ans = 0;
	if(x <= n)
	{
		ans = getSum(x);
	}
	else{
		ll sum1 = getSum(n);
		ll rem = x-n;

		ll sum2 = getSum(n-1) - getSum(rem);


		ans = sum1+sum2;
	}
	return ans<k;
}



void solve()
{
	cin >> n >> k;
	ll l = 0, r= 2*n-1;
	while(l<=r)
	{
		ll mid = l +(r-l)/2;
		if(ok(mid))
		{
			l = mid +1;
		}
		else{
			r = mid - 1;
		}
	}
	cout<< l<<endl;
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