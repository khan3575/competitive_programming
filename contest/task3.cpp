#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for(int &i : a) cin >> i;
	for(int &i : b) cin >> i;

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	ll sum  = 0;
	int j = n-1;
	for(i=m-1; i>=0; i--)
	{
		if(b[i] != a[j])
		{
			sum += (b[i]+a[j]);
			b.pop_back();
			a.pop_back();
			j--;
		}
		else{
			int temp = b[]
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
}