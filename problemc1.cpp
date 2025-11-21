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
	vector<int>a(n),b(n);
	
	for(int i = 0; i< n;i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i< n; i++)
	{
		cin >> b[i];
	}
	bool found=false;
	for(int i = 30; i>=0; i--)
	{
		int dif =0;
		int mx_idx = -1;
		for(int j = 0; j < n; j++)
		{

			if(((a[j]>>i)&1) != ((b[j]>>i)&1))
			{
				dif++;
				mx_idx= j;
			}
		}

		if(dif%2==0)
		{
			continue;
		}
		bool found=true;
		if(mx_idx&1)
		{
			cout<<"Mai\n";
		}
		else{
			cout<<"Ajisai\n";
		}
		return;
	}
	if(!found)	cout<<"Tie\n";



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