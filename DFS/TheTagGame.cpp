#include<iostream>
#include <vector>
#define ll long long int
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define pb push_back

using namespace std;
const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<int> edges[N];

void dfs(vector<ll>& heights, ll vertex, ll parent = -1) {
    for (ll child : edges[vertex]) {
        if (child == parent) continue;
        heights[child] = heights[vertex] + 1;
        dfs(heights, child, vertex);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, x;
    cin >> n >> x;

    f(i, 0, n-1){
        ll u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<ll> h1(n + 1), h2(n + 1);

    dfs(h1, 1);
    dfs(h2, x);

    ll ans = 0;
    cf(i, 1, n){
        if (h1[i] > h2[i])
            ans = max(ans, 2 * h1[i]);
    }
    cout << ans << endl;

    return 0;
}