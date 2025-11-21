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
	vector<int>v(n);
	for(auto &i : v) cin >> i;

	int l = 0, r= n-1;
	int last_turn_sum = 0;
	int curent_turn_sum = 0;
	bool turn = true;
	int cnt=1;
	ll alice =0, bob=0;
	while(l<=r)
	{
		//cout<<"i "<<curent_turn_sum<<" "<<last_turn_sum<<endl;
		if(curent_turn_sum>last_turn_sum)
		{
			cnt++;
			last_turn_sum = curent_turn_sum;
			curent_turn_sum=0;
			if(turn)
			{
				alice+=last_turn_sum;
			}
			else{
				bob+= last_turn_sum;
			}
			turn = !turn;

		}
		if(turn)
		{
			curent_turn_sum+=v[l];
			l++;
		}
		else{	
			curent_turn_sum+=v[r];
			r--;
		}
	}
	if(curent_turn_sum>0)
	{
		if(turn)
		{
			alice+=curent_turn_sum;
		}
		else{
			bob+= curent_turn_sum;
		}
	}

	
	cout<<cnt<< " "<<alice<<" "<<bob<<endl;
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