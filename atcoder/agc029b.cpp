#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


void solve()
{

	int n;
	cin>>n;
	vector<int>v(n);
	int even =0, odd= 0;
	for(int i = 0; i < n; i++)
	{
		cin>> v[i];
		if(v[i]&1)
		{
			odd++;
		}
		else{
			even++;
		}
	}
	if(odd==0 || even==0)
	{
		for(auto i: v)
		{
			cout<<i<<" ";
		}
		cout<<endl;
	}

	else{
		sort(v.begin(),v.end());
		for(auto i: v)
		{
			cout<<i<<" ";
		}
		cout<<endl;
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