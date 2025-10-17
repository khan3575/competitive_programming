#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isNonDecreasing(string s)
{
	bool ok=true;
	for(int i=1; i <(int)s.size(); i++)
	{
		if(s[i-1]>s[i])
		{
			ok=false;
			break;
		}
	}	
	return ok;
}

bool isPalindrome(string s)
{
	int n = s.size();
	bool ok=true;
	for(int i = 0; i < n/2 ; i++)
	{
		if(s[i]==s[n-i-1])
		{
			continue;
		}
		else{
			ok=false;
		}
	}
	return ok;
}

void solve()
{
	int n;
	cin >> n;
	int mx=0;
	string s;
	cin >> s;
	vector<int>ans;
	bool ok=false;

	for(int i = 0; i < (1<<n); i++)
	{
		string a="", b="";
		for(int j= 0; j<n;j++)
		{
			if((i>>j)&1)
			{
				a+= s[j];
			}
			else{
				b+= s[j];
			}
		}
		//cout<< a <<" "<< b<<endl;
		if(isNonDecreasing(a) && isPalindrome(b))
		{
			//cout<< a<<" "<<b<<endl;
			int cnt= 0;
			ok=true;
			for(int  k = 0; k<n; k++)
			{
				if((i>>k)&1)
				{
					ans.push_back(k+1);
				}
			}
			break;

		}
		if(isNonDecreasing(b)&& isPalindrome(b))
		{
			//cout<< a<<" "<<b<<endl;
			int cnt= 0;
			ok = true;
			for(int  k = 0; k<n; k++)
			{
				if(((i>>k)&1) == 0)
				{
					ans.push_back(k+1);
				}
			}
			break;
		}
		
	}
	cout<<ans.size()<<endl;
	for(auto i : ans)
	{
		cout<< i<<" ";
	}
	cout<<'\n';
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