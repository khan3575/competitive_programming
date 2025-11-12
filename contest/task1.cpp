#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


void solve()
{
	int x, y;
	cin >> x >> y;
	int s=0,a=0;
	for(int i =x; i<=y; i+=x)
	{
		if(i&1)
		{
			s+=i;
		}
		else{
			a+=i;
		}
	}
	//cout<<s<<" "<<a<<endl;
	if(a>=s)
	{
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
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