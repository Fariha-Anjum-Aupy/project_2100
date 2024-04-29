#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
#define f(i,s,e) for(long long int i = s; i < e; i++)
#define cf(i,s,e) for(long long int i = s; i <= e; i++)
#define rf(i,e,s) for(long long int i = e-1; i >= s; i--)
#define pb push_back
#define eb emplace_back
#define py cout << "Yes" << endl
#define pn cout << "No" << endl

using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const ll INF = 1e18 + 10;
const double PI = 3.141592653589793;

vector<pair<int, int>> edges[N];
vector<ll> dist(N, INF);
vector<int> vis(N, 0);

vector<int> dijkstra(int source, int n){
    set<pair<ll, int>> st;
    st.insert({0, source});
    dist[source] = 0;
    vector<int> seq;
    vector<int> parent(n + 1, -1);

    while(!st.empty()){
        auto node = *st.begin();
        int par = node.second;
        ll d = node.first;
        st.erase(node);

        if(vis[par]) continue;
        vis[par] = 1;

        for(auto child: edges[par]){
            int child_v = child.first;
            int wt = child.second;
            if(dist[par] + wt < dist[child_v]){
                dist[child_v] = dist[par] + wt;
                st.insert({dist[child_v], child_v});
                parent[child_v] = par; 
            }
        }
    }

    int curr = n;
    while (curr != -1) {
        seq.pb(curr);
        curr = parent[curr];
    }
    reverse(seq.begin(), seq.end());

    return seq;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    f(i, 0, m){
        int x, y, wt;
        cin >> x >> y >> wt;
        edges[x].pb({y, wt});
        edges[y].pb({x, wt});
    }

    vector<int> ans = dijkstra(1, n);
    if(dist[n] != INF){
        for(auto i: ans){
            cout << i << " ";
        }
    }

    else cout << -1 << endl;

    return 0;
}