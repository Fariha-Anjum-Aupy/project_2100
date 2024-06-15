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
int sz[N];

void make(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find(int v){
    if(parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

ll power(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1){
            ans = (ans * a) % M;
        }
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cf(i, 1, n) make(i);

        vector<int> a(n+1), b(n+1), c(n+1);
        cf(i, 1, n) cin >> a[i];
        cf(i, 1, n) cin >> b[i];
        cf(i, 1, n) cin >> c[i];
        cf(i, 1, n){
            Union(a[i], b[i]);
            if(a[i] == b[i]) c[i] = b[i];
        }

        set<int> st;
        cf(i, 1, n){
            st.insert(find(i));
        }
        cf(i, 1, n){
            if(c[i]) st.erase(find(c[i]));
        }

        cout << power(2, st.size()) << endl;
    }

    return 0;
}