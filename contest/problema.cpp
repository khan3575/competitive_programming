#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


void solve()
{
	int n;
	cin >> n;
	vector<int>v(n);
	int mx = 0;
	for(int i = 0 ; i <  n; i++)
	{
		cin >> v[i];
		mx= max(v[i], mx);
		if(i&1)
		{
			v[i]=mx;
		}
	}
	// for (int i :v)
	// {
	// 	cout<<i<< " ";
	// }
	// cout<<endl;
	int ans=0; 
	for(int i = 0; i<n; i+=2)
	{
		if(i==0)
		{
			if(v[i]>=v[i+1])
			{
				ans+= v[i]-v[i+1]+1;
			}

		}
		else if(i==n-1)
		{
			//cout<<v[i]<<" "<<v[i-1]<<endl;
			if(v[i]>=v[i-1])
			{
				//cout<< "ans "<<v[i]-v[i-1]+1<<endl;
				ans+= v[i]-v[i-1]+1;
			}
			//cout<<i<<endl;
		}
		else{
			int mn = min(v[i-1],v[i+1]);
			int mx = max(v[i-1],v[i+1]);
			// /cout<<"mn "<<mn<<" "<<mx<<endl;
			if(v[i]>=mn || v[i]>=mx)
			{
				ans+= v[i]-mn+1;
			}
		}
		//cout<<"i "<<i<< " "<<ans<<endl;
	}

	cout<<ans<<endl;



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