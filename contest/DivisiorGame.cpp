#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int>v(1005);

bool canWin(int n)
{
	if(v[n]!=-1)
	{
		return v[n];
	} 
	for(int x= 1; x<=2; ++x)
	{
		if(n%x==0)
		{
			if(canWin(n-x) == 0)
			{
				v[n] = 1;
				return 1;
			}
		}
	}
	v[n] = 0;
	return v[n];
}

bool divisorGame(int n) {
	v.assign(n+5, -1);
	if(n>=1)
	{
		v[1] = 0;
	}
	return canWin(n);

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t=1;
	//cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout<<divisorGame(n);
	}
}