#include <bits/stdc++.h>
using namespace std;

using ll   =  long long;
using ull  =  unsigned long long;
using ld   =  long double;

#define endl            '\n'
#define all(x)          (x).begin(), (x).end()
#define rall(x)         (x).rbegin(), (x).rend()
#define point(x)        fixed << setprecision(x)
#define FastIo          ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define sz(x)           (int)x.size()

const ld pi = acos(-1);
const ll mod = 1e9 + 7;
const ll mxn = 1e5 + 5;
const int N = 200;
vector<vector<int>>adj;


void Plz_Ac() {
	int n;
	cin >> n;
	adj.assign(N + 5, vector<int>());
	vector<int>v(n + 5);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (i <= n) {

			adj[i].push_back(i + 1);
		}
	}
	for (int i = 0; i < n; i++)
	{
		int jump_next = v[i] + i + 1;

		if (jump_next <= 0)
		{
			continue;
		}
		else if (jump_next > n + 1)
		{
			continue;
		} else {
			adj[i + 1].push_back(jump_next);
		}
	}

	vector<bool>vis(N + 5, 0);
	vector<int>dis(N + 5, 0);
	deque<int>dq;
	dq.push_back(1);
	vis[1] = true;
	dis[1] = 0;
	while (!dq.empty())
	{
		int u = dq.front();
		dq.pop_front();
		//cout << u << " par ";
		vis[u] = true;
		if (u == n + 1)
		{
			break;
		}
		for (auto child : adj[u])
		{
			if (vis[child])
			{
				continue;
			}
			//cout << child << " ";
			
			dis[child] = dis[u] + 1;
			dq.push_front(child);
		}
	}
	cout << dis[n + 1] << endl;



}

int main() {
	FastIo;
	int test = 1;
	cin >> test;
	while (test--) {
		Plz_Ac();
	}
	return 0;
}