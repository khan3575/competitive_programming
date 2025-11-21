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
	vector<int> v(n);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(),v.end());
	int ans = 0; 


	for(int i= 1; i <= 100;i++)
	{
		int l = 0,r = n-1;
		int temp = 0;
		while(l<r)
		{
			if(v[l]+v[r]==i)
			{
				temp++;
				l++;
				r--;
			}
			else if(v[l]+v[r]<i)
			{
				l++;
			}
			else{
				r--;
			}
		}
		ans = max(ans,temp);
	}
	cout<<ans<<endl;
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