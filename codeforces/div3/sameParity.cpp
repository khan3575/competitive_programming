#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)


void solve()
{
	ll n;
	cin >> n;

	ll a =-1, b=-1, c=-1;
	bool found=false;
	for(ll i = 2; i<=sqrtl(n); i++)
	{
		if(n%i == 0)
		{
			a = i;
			ll rem = n/a;
			for(ll j= i+1; j<=sqrtl(n); j++)
			{
				if(rem%j==0 && rem/j>  j)
				{
					b=j;
					c = rem/j;
					found = true;
					break;
				}
			}
			if(found)
				{break;}
		}
		if(found) break;
	}
	if(found)
	{
		cout<<"YES\n";
		cout<<a <<" "<<b<<" "<<c<<endl;
	}
	else{
		cout<<"NO\n";
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