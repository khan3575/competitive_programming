#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


void solve()
{
	int n;
	cin >> n;
	vector<int>v(n);
	int mx = 0;
	for(int i = 0; i< n; i++)
	{
		cin >> v[i];
		mx = max(mx, v[i]);
	}
	sort(v.begin(),v.end());
	
	
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