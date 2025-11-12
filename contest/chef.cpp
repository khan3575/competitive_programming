#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


void solve()
{
	int n;
	cin >> n;
	vector<pair<int,int>>v(n);
	for(int i = 0; i <n; i++)
	{
		int x;
		cin >>x;
		v[i]= make_pair(x,i);
	}

	sort(v.begin(),v.end());
	vector<ll>b;
	for(int i =  0; i <n-1; i++)
	{
		ll x = v[i].first;
		ll y = v[i+1].first;
		b .push_back((x+y)/2);
	}
	vector<ll> ans(n);
	if(n>=1)
	{
		ans[0]=-1;
	}
	if(n>=2){
		ans[n-1]= -1;
	}
	for(int i =1 ; i<n-1; i++)
	{
		ans[i] = b[i]-b[i-1];
	}

	vector<ll>final_ans(n);

	for(int i = 0 ; i < n; i++)
	{
		final_ans[v[i].second]= ans[i];
	}
	for(auto i: final_ans)
	{
		cout<<i<<" ";
	}
	cout<<endl;
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