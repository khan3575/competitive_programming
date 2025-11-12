#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n';
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
const ll mod = 1e9+7;
const ll N = 1e6+5;
vector<ll> fact(N);
vector<ll> invFact(N);
ll bigMod(ll b, ll p, ll m)
{
	ll r = 1;
	b%=m;
	while(p>0)
	{
		if(p&1)
		{
			r = (r*b)%m;
		}
		p/=2;
		b = (b*b)%m;
	}
	return r;
}
ll modInverser(ll n, ll m)
{
	return bigMod(n, m-2, m);
}

void preCalFact()
{
	fact[0]=1;
	invFact[0] = modInverser(1,mod);
	for(int i = 1; i<N; i++)
	{
		fact[i]=  (fact[i-1]*i)%mod;
		invFact[i] = modInverser(fact[i], mod);
	}
}

ll nCr(ll n, ll r)
{
	return (((fact[n]*invFact[r])%mod)*invFact[n-r])%mod;
}

void solve()
{
	ll n, m;
	cin >> n >> m;
	ll ans = nCr(n,m);
	cout<<ans<<endl;	
}


int main()
{
	preCalFact();
	unsyncIO;
	int t=1;
	cin >> t; 
	while(t--){
		solve();
	}
}