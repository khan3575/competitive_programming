#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n;
map<int,bool>feq;
bool sumOfDigit(ll x)
{
	ll sum = 0;
	while(x)
	{
		ll dig = x%10;
		sum+=dig;
		x/=10;
	}
	return sum == 10; 
}

bool isOk(ll x)
{
	ll cnt =0;
	for(ll i = 1; i<=x; i+=9)
	{
		//cout<<i<<" "<<sumOfDigit(i)<<endl;
		if(sumOfDigit(i))
		{
			cnt++;
		}
		if(cnt>=n)
		{
			break;
		}
	}

	return cnt>=n;

}


void solve()
{
	
	cin >> n;
	
	ll l =0, r=1e8+5;

	while(l<=r)
	{

		ll mid  = l + (r - l)/2;
		//cout<<mid<<endl;
		if(isOk(mid))
		{
			r= mid-1;
		}
		else{
			l = mid + 1;
		}
	}
	cout<<l<<'\n';
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t=1;
	//cin >> t;
	while(t--){
		solve();
	}
}