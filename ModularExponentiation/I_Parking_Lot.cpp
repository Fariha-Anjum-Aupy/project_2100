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
const int M = 99;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
const double PI = 3.141592653589793;

ll power(ll a, ll b) {
    ll result = 1;
    while (b > 0) {
        if (b & 1) result *= a;
        a *= a;
        b >>= 1;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    
    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }

    ll ways = 24 * power(4, n - 3) + 36 * (n - 3) * power(4, n - 4);
    
    cout << ways << endl;
    
    return 0;
}
