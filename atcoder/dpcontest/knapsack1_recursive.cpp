#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll knapsack(int w, vector<int> &weight, vector<int>&value, int n)
{
	if(n==0  || w ==0)
	{
		return 0;
	}

	ll pick = 0;

	if(weight[n-1]<=w)
	{
		pick = value[n-1] + knapsack(w- weight[n-1], weight, value, n-1);
	}
	ll notPick = knapsack(w, weight, value, n-1);

	return max(pick, notPick);

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, w;
	cin >> n >> w;
	vector<int>weight(n),value(n);
	for(int  i = 0; i < n; i++)
	{
		cin>> weight[i] >> value[i];
	}
	cout<<knapsack(w,weight,value,n)<<endl;

}