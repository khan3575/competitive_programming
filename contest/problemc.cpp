#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=2e5+5;
vector<int>spf(N);
void sieve()
{
	for(int i = 2; i < N; i++)
	{
		if(spf[i]==0)
		{
			for(int j = i; j<N; j+=i)
			{
				if(spf[j]==0)
				{
					spf[j]=i;
				}
			}
		}
	}
}

void solved()
{
	vector<int>freq(N);
	vector<int>div(N);
	int n;
	cin >> n;
	//cout<<"n "<<n<<endl;
	vector<int>v(n),b(n);
	int mx =0;
	set<int>st;
	for(int i = 0; i <n; i++)
	{
		cin>>v[i];
		mx = max(mx, v[i]);
		freq[v[i]]++;
		st.insert(v[i]);
	}

	for(int j = 0; j<n; j++)
	{
		cin >> b[j];
	}
	bool isZero=false;
	for(int i = 2; i<=mx; i++)
	{
		int cnt = 0;
		for(int j = i; j<=mx; j+=i)
		{
			cnt+=freq[j];
			if(cnt>=2)
			{
				break;
			}
		}
		div[i]= cnt;
		if(cnt>=2){
			isZero=true;
			break;
		}
	}
	if(isZero)
	{
		cout<<0<<endl;
		return;
	}
	bool isOne= false;
	for(int i : st)
	{
		int x = i+1;
		int lastprime = -1;
		while(x>1)
		{
			int p = spf[x];
			if(p!=lastprime)
			{
				if(div[p]>=1)
				{
					isOne=true;
					break;
				}
				lastprime=p;

			}
			while(x%p == 0)
			{
				x/=p;
			}
		}
		if(isOne)
		{
			break;
		}
	}
	if(isOne)
	{
		cout<<1<<endl;
	}
	else{
		cout<<2<<endl;
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	sieve();
	
	int t=1;
	cin >> t;
	while(t--){
		solved();
	}
}