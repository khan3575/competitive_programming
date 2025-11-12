#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isOK(ll mid , vector<int>v, int n)
{
	
}

void solve()
{
	int n, k , x;
	cin >> n >> k >> x;
	vector<int>v(n);
	for(int i = 0; i < n;i++)
	{
		cin>> v[i];
	}
	sort(v.begin(),v.end());
	ll l = 0, r=x;
	while(l<=r)
	{
		ll mid = l + (r-l)/2;

		if(isOk(mid, v, n))
		{

		}
		else{

		}
	}
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
	return 0;
}