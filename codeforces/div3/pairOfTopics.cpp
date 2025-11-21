#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)


void solve()
{
	int n;
	cin >> n;
	vector<ll> a(n),b(n);
	for(int i = 0; i< n; i++)
	{
		cin >>a[i];
	}
	for(int i = 0; i< n; i++)
	{
		cin >> b[i];
	}

	vector<ll> v(n);
	for(int i = 0;  i< n;i++)
	{
		ll d = a[i]-b[i];
		v[i]=d;
	}
	sort(v.begin(),v.end());
	int l = 0, r= n-1;
	ll ans=0;
	while(l<r)
	{
		if(v[l]+v[r]<=0)
		{
			l++;
		}
		else{
			ans+= (r-l);
			r--;
		}
	}
	cout<<ans<<endl;

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