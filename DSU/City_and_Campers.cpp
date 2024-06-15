#include<iostream>
#include <bits/stdc++.h>
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
const int INF = 1e9 + 10;
const double PI = 3.141592653589793;

int parent[N];
int size[N];
multiset<int> sz;

void make(int v){
    parent[v] = v;
    size[v] = 1;
    sz.insert(1);
}

int find(int v){
    if(parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void merge(int a, int b){
    sz.erase(sz.find(size[a]));
    sz.erase(sz.find(size[b]));
    
    sz.insert(size[a] + size[b]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        //union by size
        if(size[a] < size[b]) swap(a, b);
        parent[b] = a;
        merge(a, b);
        size[a] += size[b];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    cf(i, 1, n) make(i);

    while(q--){
        int u, v;
        cin >> u >> v;
        Union(u, v);

        if(sz.size() == 1) cout << 0 << endl;
        else{
            int min = *(sz.begin());
            int max = *(--sz.end());
            cout << max - min << endl;
        }
    }

    return 0;
}