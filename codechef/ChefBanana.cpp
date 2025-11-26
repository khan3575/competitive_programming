#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)


void solve()
{
	int n, m;
	cin >> n >> m;
	vector<ll>v(n);
	for(int i = 0; i < n; i++)
	{
		cin>> v[i];
	}
	ll l = 1, r= 1e15;
	
	auto check = [&](ll mid) -> bool{
		ll ans = 0;
		for(int i = 0 ; i< n; i++)
		{
			ll x = ((v[i]+mid-1)/ mid);
			ans+=x;
		}
		//cout<<mid<<" "<<ans<<endl;
		return ans<= m;  
	};

	while(l<=r)
	{
		ll mid = l + (r-l)/2;

		if(check(mid))
		{
			r = mid -1;
		}
		else{
			l = mid + 1;
		}
	}
	cout<< l<<endl;

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