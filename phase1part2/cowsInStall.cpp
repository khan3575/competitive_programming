#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, k;
vector<int> v;
bool ans(ll mid)
{
	int cnt = 0;
	int last = v[0];

	for(int i = 0; i < n; i++)
	{
		if( v[i]-last >= mid)
		{
			cnt++;
			last=v[i];
		}
	}

	if(cnt>= k-1)
	{
		return true;
	}
	else{
		return false;
	}
}

void solve()
{


	cin >> n >> k;
	v.resize(n);
	//cout<<v.size()<<endl;
	for(int i = 0; i< n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	ll l=0 , r= INT_MAX;
	while(l<=r)
	{
		ll mid = (l + r) >> 1;

		if(ans(mid))
		{
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}
	cout<< r<<'\n';

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t=1;
	//cin >> t;

	while(t--){
		solve();
	}
}