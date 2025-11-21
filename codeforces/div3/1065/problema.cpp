#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)


void solve()
{
	int n;
	cin >>n;
	if(n%2==1)
	{
		cout<<0<<endl;
	}
	else{
		int numberOfTwo = n/2; 
		int numberOfFour = 0;
		int ans= 0;
		for(int i = numberOfTwo; i>=0; i-=2)
		{
			int x = (numberOfTwo*2) + (numberOfFour*4);
			if(x == n)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
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