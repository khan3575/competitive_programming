#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n';
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)


void solve()
{
	int n;
	cin >> n;
	vector<int>v(n);
	for(int i = 0 ;i < n;i++)
	{
		cin >> v[i];
	}
	string x;
	cin >>x;
	if(x[0]=='1' || x[n-1]=='1')
	{
		cout<<-1<<endl;
		return;
	}
	bool ok = false;
	for(int i = 0; i < n; i++)
	{
		if(x[i]=='1')
		{
			ok=true;
			break;
		}
	}
	if(!ok)
	{
		cout<<0<<endl;
	}

	int l = 0, r= n-1;
	int mn = min(v[l], v[r]);
	int mx = max(v[l],v[r]);

	for(int i = 1; i< n-1; i++)
	{
		if(x[i]=='1')
		{
			if(!(v[i] > mn && v[i]<mx))
			{
				cout<<-1<<endl;
				return;
			}
		}
	}
	cout<<1<<endl;
	cout<<1<<" "<<n<<endl;
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