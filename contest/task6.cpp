#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


void solve()
{
	int n, m;
	cin >> n >>  m;
	vector<int>a(n),b(n);
	priority_queue<int> cnta,cntb;
	
	for(int i = 0 ; i < n; i++)
	{
		cin >> a[i];
		cnta.push(a  [i]);
	}
	for(int i = 0; i < m; i++)
	{
		cin >>b[i];
		cntb.push(b[i]);
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