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

vector<ll> edges[N];
bool vis[N];
vector<ll> seq;
bool flag = false;
ll a, b;

void dfs(ll vertex){
    vis[vertex] = true;
    seq.pb(vertex);
    if(vertex == b){
        flag = true;
        return;
    }

    for(int child : edges[vertex]){
        if(vis[child]) continue;
        dfs(child);
        if(flag) return;
    }
    seq.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;

    queue<ll> q;
    q.push(a);

    while(!q.empty()){
        int temp = q.front();
        q.pop();

        int x = 2*temp;
        int y = 10*temp + 1;

        if(x <= b){
            edges[temp].pb(x);
            edges[x].pb(temp);
            q.push(x);
        }

        if(y <= b){
            edges[temp].pb(y);
            edges[y].pb(temp);
            q.push(y);
        }
    }

    dfs(a);

    if(seq.size() == 0) pn;
    else{
        py;
        cout << seq.size() << endl;
        for(auto i : seq){
            cout << i << " ";
        }
    }

    return 0;
}