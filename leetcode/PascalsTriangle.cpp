#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
	vector<vector<int>>v;
	if(numRows<1)
	{
		return v;
	}
	v.resize(numRows);
	for(int i = 0; i < numRows; i++)
	{
		v[i].resize(i+1);
		v[i][0]=1;
		v[i][1]=1;
		for(int j = 1; j < i; j++)
		{
			v[i][j] = v[i-1][j-1] + v[i-1][j];
		}
	}
	return v;
}

int main()
{
	int n;
	cin >> n;
	generate(n);

	return 0;
}