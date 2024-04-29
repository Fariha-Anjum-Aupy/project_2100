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
const int M = 2e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
const double PI = 3.141592653589793;

vector<int> edges[N];
int vis[N];
unordered_map<int, int> mp;

vector<int> bfs(int vertex) {
    queue<int> q;
    q.push(vertex);
    vis[vertex] = 1;
    vector<int> seq;

    while (!q.empty()) {
        int par = q.front();
        q.pop();
        seq.push_back(par);

        for (int child : edges[par]) {
            if (!vis[child]) {
                q.push(child);
                vis[child] = 1;
            }
        }
    }
    return seq;
}

bool cmp(int a,int b){
    return mp[a] < mp[b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    f(i, 0, n-1){
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    vector<int> v(n);

    f(i, 0, n){
        cin >> v[i];
        mp[v[i]] = i;
    }

    cf(i, 1, n){
        sort(edges[i].begin(), edges[i].end(), cmp);
    }

    vector<int> seq = bfs(1);

    if (seq == v) py;
    else pn;

    return 0;
}