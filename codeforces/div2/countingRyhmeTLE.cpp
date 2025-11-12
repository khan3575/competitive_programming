#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int N=1e6+5;

void solve()
{
	int n;
	cin >> n;
	vector<int>v(n);
	vector<int>freq(N+1,0);
	int mx = 0;
	for(int i = 0; i< n;i++)
	{
		cin >>v[i];
		mx = max(mx, v[i]);
		freq[v[i]]++;
	}
	
	sort(v.begin(),v.end());
	vector<int>cnt(N+1,0);
	vector<bool> is_bad_gcd(mx+1,false);
	for(int i =1; i<=mx; i++)
	{
		if(freq[i]>0)
		{
			for(int j = i; j<= mx; j+=i)
			{
				is_bad_gcd[j]=true;
			}
		}
	}
	for(int i = 1; i<=mx; i++)
	{
		for(int j = i; j<=mx; j+=i)
		{
			cnt[i] += freq[j];
		}
		
	}
	for(int i = 1; i<= mx; i++)
	{
		int a = cnt[i];
		cnt[i] = a*(a-1) / 2;
	}
	for(int i=mx; i>=1; i--)
	{
		int temp =0;
		for(int j = i+i; j<=mx; j+=i)
		{
			temp+= cnt[j];
		}
		cnt[i] -= temp;
	} 

	ll total_good_pairs = 0;
	for(int g = 1; g <= mx ; g++)
	{
		if(!is_bad_gcd[g])
		{
			total_good_pairs+=cnt[g];
		}
	}
	cout<<total_good_pairs<<endl;

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