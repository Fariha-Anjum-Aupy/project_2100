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

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int s, q;
    cin >> s >> q;
    set<int> cont;

    while(q--){
        int x;
        cin >> x;
        int ans = gcd(s, x);

        if(cont.find(ans) != cont.end()) cout << -1 << endl;
        else{
            cout << ans << endl;
            cont.insert(ans);
        }
    }

    return 0;
}