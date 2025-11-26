#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)


void solve()
{
	int n, t;
	cin >> n >> t;

	vector<int>v(n);
	for(int i = 0; i< n; i++)
	{
		cin >> v[i];
	}
	
	auto check = [&](ll x)->bool{
		ll total_product =0;
		for(int i = 0; i< n; i++)
		{
			total_product+=(x/v[i]);
			if(total_product>t){
				break;
			}
		}
		return total_product>=t;
	};

	ll l = 0, r= 1e18;
	
	while(l<=r)
	{
		ll mid = l+(r-l)/2;
		if(check(mid)){
			r = mid-1;
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
	//cin >> t; 
	while(t--){
		solve();
	}
}