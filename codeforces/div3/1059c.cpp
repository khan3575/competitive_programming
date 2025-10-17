#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


void solve()
{
	ll a, b;
	cin >> a  >> b;
	if(a==b)
	{
		cout<<0<<endl;
		return;
	}
	int last_a=-1,last_b=-1;
	for(int i = 0; i< 32; i++)
	{
		if((a>>i)&1)
		{
			last_a=i;
		}
		if((b>>i)&1)
		{
			last_b= i;
		}
	}

	if(last_b>last_a)
	{
		cout<<-1<<endl;
		return;
	}
	ll x = a^b;
	if(x<=a)
	{
		cout<<1<<'\n'<<x<<'\n';
	}
	else{
		ll y = (1LL<<last_a)-1;
		ll aa = y^a;
		if((b^aa)<= aa)
		{
			cout<< 2<<'\n'<< y<<" "<< (b^aa)<<'\n';
		}
		else{
			cout<<-1<<endl;
		}
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