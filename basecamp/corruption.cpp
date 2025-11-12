#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


void solve()
{
	int n, k;
	cin >> n >> k;
	priority_queue<long double, vector<long double>, greater<long double>>q;
	for(int i = 0; i< n; i++)
	{
		long double x;
		cin >> x;
		q.push(x);
	}
	while(q.size()>1)
	{
		long double a,b;
		a=q.top();
		q.pop();
		b=q.top();
		cout<<a <<" "<< b<<endl;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t=1;
	// cin >> t;
	while(t--){
		solve();
	}
}