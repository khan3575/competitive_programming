#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)


void solve()
{
	int n, m;
	cin >> n >>m;
	multiset<ll>q;
	int x;
	for(int i = 0; i<n;i++)
	{
		cin>>x;
		q.insert(x);
	}
	vector<pair<ll,ll>>v(m);
	for(int i = 0; i< m; i++)
	{
		cin >>v[i].first;
	}
	for(int i = 0; i<m; i++)
	{
		cin >>v[i].second;
	}

	auto cmp = [&](const pair<ll,ll> &a, const pair<ll,ll> &b)->bool{
		if(a.second==0 ^ b.second == 0)
		{
			return a.second >b.second;
		}
		return a.first < b.first;
	};
	
	sort(v.begin(),v.end(),cmp);

	
	ll ans=0;
	for(int i = 0; i< m; i++)
	{
		auto it = q.lower_bound(v[i].first);
		//cout<<v[i].first<< " "<<v[i].second<<endl;
		if(it != q.end() )
		{
			ll x = *it;
			//cout<<"to insert " <<max(x,v[i].second)<<endl;
			q.erase(it);
			ans++;

			if(v[i].second >0)
			{
				q.insert(max(x, v[i].second));
			}
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