#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)


void solve()
{
	int n;
	cin>> n;
	vector<ll>v(n);
	vector<ll>ev;
	vector<ll>od;
	for(int i = 0; i< n; i++)
	{
		cin >>v[i];
		if(v[i]&1)
		{
			od.push_back(v[i]);
		}
		else{
			ev.push_back(v[i]);
		}
	}
	if((int)ev.size()>1)
	{
		cout<< ev[0]<<" "<<ev[1]<<endl;
		return;
	}
	int m = od.size();
	for(int i = 0; i<m; i++)
	{
		ll
	}

	cout<<-1<<endl;
	
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