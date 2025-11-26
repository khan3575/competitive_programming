#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)



int main()
{
	
	unsyncIO;
	
	int n, m;
	int tests=1;
	while(cin >> n >> m)
	{
		if(n==0 && m == 0)
		{
			break;
		}
		vector<int>v(n);
		for(int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(),v.end());
		cout<<"CASE# "<<tests<<":\n";
		while(m--)
		{
			int x;
			cin >> x;
			auto it = lower_bound(v.begin(),v.end(),x);
			if(it == v.end() || *it !=x)
			{
				cout<<x<<" not found\n";
			}
			else{
				cout<< x<<" found at "<<(it-v.begin()+1)<<endl;
			}

		}
		//answer goes here
		tests++;
	}
}