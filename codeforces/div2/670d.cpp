#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)


void solve()
{
	int n, k;
	cin  >> n >> k;
	vector<ll>a(n),b(n);
	for(int i = 0; i < n; i++)
	{
		cin >>a[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	ll l = 1, r= 1e10;

	auto check = [&](ll x) ->bool{
		ll magicPowder=0;
		for(int i = 0; i< n; i++)
		{
			ll y = a[i]*x;
			ll dif = max(0LL, y-b[i]);
			magicPowder+= dif;
			if(magicPowder>k)
			{
				break;
			}
		}
		return magicPowder>k;
	};

	while(l<=r)
	{

		ll mid = l + (r-l)/2;
		//cout<< mid<<endl; 	
		if(check(mid))
		{
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	cout<<r<<endl;
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