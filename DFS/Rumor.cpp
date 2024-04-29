#include<iostream>
#include <bits/stdc++.h>
#define ll long long int
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define py cout << "YES" << endl
#define pn cout << "NO" << endl

using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;

ll c[N];
vector<int> edges[N];
bool vis[N];

ll dfs(ll n){
    ll smol = c[n];
    vis[n] = 1;

    for(auto i : edges[n]){
        if(!vis[i]) smol = min(smol, dfs(i));
    }
    return smol;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;

    f(i, 0, n) cin >> c[i];

    f(i, 0, m){
        ll u, v;
        cin >> u >> v;
        u--; v--;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    ll ans = 0;

    f(i, 0, n){
        if(!vis[i]){
            ans += dfs(i);
        }
    }

    cout << ans << endl;

    return 0;
}