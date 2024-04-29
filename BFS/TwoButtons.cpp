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
const int N = 1e4 + 10;
const int INF = 1e9 + 10;
const double PI = 3.141592653589793;

int vis[N];
int level[N];

int bfs(int n, int m) {
    queue<int> q;
    
    q.push(n);
    vis[n] = 1;
    level[n] = 0;
    
    while (!q.empty()){
        int curr = q.front();
        q.pop();
        
        if (curr == m){
            return level[m];
        }
        
        int a = curr * 2;
        int b = curr - 1;
        
        if (a <= 10000 && !vis[a]){
            q.push(a);
            vis[a] = 1;
            level[a] = level[curr] + 1;
        }
        if (b > 0 && !vis[b]){
            q.push(b);
            vis[b] = 1;
            level[b] = level[curr] + 1;
        }
    }
    
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    cout << bfs(n, m) << endl;

    return 0;
}