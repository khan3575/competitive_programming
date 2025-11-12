#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)

ll ncr (ll n)
{
	return (n*(n-1))/2;
}

void solve()
{
	int n;
	cin >> n;
	vector<ll>v(n);
	vector<ll> freq(n+1);
	for(int i = 0; i< n;i++)
	{
		cin >> v[i];
		freq[v[i]]++;
	}
	if(freq[1]>0)
	{
		cout<<0<<endl;
		return;
	}
	vector<ll>cnt(n+1); 
	for(int i = 1; i<= n; i++)
	{
		for(int j = i; j<=n; j+=i)
		{
			cnt[i] += freq[j];
		}
	}

	for(int i = 1; i <= n; i++)
	{
		ll a = ncr(cnt[i]);
		cnt[i]=a;
	}
	//now this cnt contain all the pair possible with that number only


	for(int i = n; i>0; i--)
	{
		ll temp =0;
		for(int j = i+i; j<=n; j+=i)
		{
			temp += cnt[j];
		}
		cnt[i]-= temp;
	}
	vector<bool>is_bad(n+1);
	for(int i = 2; i<=n; i++)
	{
		if(freq[i])
		{
			for(int j = i; j<=n; j+=i)
			{
				is_bad[j]=true;
			}
		}
	}
	ll ans = 0;
	for(int i = 1; i<=n ; i++)
	{
		if(!is_bad[i])
		{
			ans+=cnt[i];
		}
	}
	cout<<ans<<endl;

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