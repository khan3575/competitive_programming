#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=1e6+5;
ll nCr(ll n)
{
	return n*(n-1)/2;
}

void solve()
{
	int n;
	cin >> n;
	int mx = 0;
	vector<int>v(n), freq(N);
	for(int i = 0; i<n; i++)
	{
		cin >>v[i];
		mx = max(mx, v[i]);
		freq[v[i]]++;
	}
	vector<ll>cnt(N,0);
	for(int i = 1; i<=mx; i++)
	{
		for(int j=i; j<=mx; j+=i)
		{
			cnt[i]+= freq[j];
		}
		//cout<< "i "<<i<<" "<<cnt[i]<<endl;
	}
	for(int i = 1; i<=mx; i++)
	{
		ll a = nCr(cnt[i]);
		cnt[i] = a;
	}

	for(int i= mx; i>=1; i--)
	{
		ll temp = 0;
		for(int j= i+i; j<=mx; j+=i)
		{
			temp+= cnt[j];
		}
		cnt[i]-= temp;
	}
	ll ans = 0;
	
	cout<<ans<<" "<<cnt[1]<<endl;


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