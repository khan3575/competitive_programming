#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)


void solve()
{
	ll n , k;
	cin >> n >> k;
	vector<ll>v(n);
	for(int i = 0; i < n; i++)
	{
		cin >>v[i];
	}

	

	ll l = 1, r= 1e9;
	auto check = [&](ll x)->bool{

		ll numOfStudent =0;
		for(int i = 0; i< n; i++)
		{
			numOfStudent+= v[i]/x;
			if(numOfStudent>=k)
			{
				return true;
			}
		}
		return numOfStudent >= k;
	};

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
	cout<<r<<endl;
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