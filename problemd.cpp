#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)


void solve()
{
	int n;
	cin >> n;
	vector<int>v(n);
	for(int i = 0; i<n; i++)
	{
		cin >> v[i];
	}

	vector<int>pref(n+1,INT_MAX);
	vector<int>suf(n+2,0);
	for(int i = 0; i< n; i++)
	{

		pref[i+1]= min(pref[i], v[i]);
	}
	for(int j = n; j >=1; j--)
	{
		// cout<< suf[j]<<" j "<<endl;
		suf[j-1] = max(suf[j],v[j-1]);
	}
	// cout<<"pref\n";
	// for(int i = 0; i <=n; i++)
	// {
	// 	cout<<pref[i]<<" ";
	// }

	// cout<<"\nsuf :"<<endl;
	// for(int j = 0; j<=n; j++)
	// {
	// 	cout<<suf[j]<<" ";
	// }
	// cout<<endl;



	bool ok = true;
	for(int i = 1; i<n; i++)
	{
		// cout<<pref[i]<< " "<< suf[i]<<endl;


		if(pref[i]>=suf[i])
		{
			ok=false;
			break;
		}
	}
	if(ok)
	{
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
	}

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