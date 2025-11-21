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
	int loc =-1;
	bool minus = false;
	for(int i = 0; i<n; i++)
	{

		cin >> v[i];
		if(i>0 && i<n-1 && v[i]==-1)
		{
			v[i]=0;
		}
	}


	if(v[0]==-1 && v[n-1]==-1)
	{
		v[0] = 0;
		v[n-1] = 0;
	}
	else if(v[0]==-1 && v[n-1]!= -1)
	{
		v[0] = v[n-1];
	}
	else if(v[0]!=-1 && v[n-1]==-1){
		v[n-1] = v[0];
	}
	//cout<<v[0] << " "<<v[n-1]<<endl;
	int ans = abs(v[n-1]-v[0]);
	cout<< ans<<endl;
	for(auto i: v)
	{
		cout<< i<<" ";
	}
	cout<<endl;
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