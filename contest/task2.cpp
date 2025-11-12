#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool cmp(pair<int,int>a, pair<int,int>b)
{
	if(a.first!=b.first){
		return a.first> b.first;
	}
	else{
		return a.second<b.second;
	}
}

void solve()
{
	int n;
	cin >>n;
	//cout<<n<<endl;

	vector<pair<int,int>>v;
	for(int i = 1; i<=n; i++)
	{
		
		int ans= __gcd(i,n);
		v.push_back({ans,i});
	}
	sort(v.begin(),v.end(),cmp);
	for(auto i: v)
	{
		cout<< i.second<<" ";
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