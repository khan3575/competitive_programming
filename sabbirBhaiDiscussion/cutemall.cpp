#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n';
#define unsyncIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
vector<vector<int>>adj;
int ans = 0;
int dfs(int u, int par)
{
    int sz = 1;
    for(int v : adj[u])
    {
        if(v== par)
        {
            continue;
        }
        int child = dfs(v,u);
        if(child%2==0)
        {
            ans++;
        }
        else{
            sz += child;
        }
    }
    return sz; 

}

void solve()
{
    int n;
    cin >> n;
    adj.assign(n+1,vector<int>());
    for(int i = 0;i < n-1; i++)
    {
        int x, y;
        cin >> x >>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(n&1)
    {
        cout<<-1<<endl;
        return;
    }

    dfs(1,0);
    cout<<ans<<endl;
}


int main()
{
    
    unsyncIO;
    int t=1;
    //cin >> t; 
    while(t--){
        solve();
    }
}