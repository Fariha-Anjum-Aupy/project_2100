#include <iostream>
#include <bits/stdc++.h>
#include <numeric>
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
const int N = 2e5 + 10;
const int INF = 1e9 + 10;
const double PI = 3.141592653589793;

vector<int> ct(N);
unordered_map<int, int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    f(i, 0, n){
        int x;
        cin >> x;
        mp[x]++;
    }

    f(i, 1, N){
        for(int j = i; j < N; j+= i){
            ct[i] += mp[j];
        }
    }

    int t;
    cin >> t;

    while(t--){
        ll p, q;
        cin >> p >> q;
        ll lcm = p*q / __gcd(p, q);

        ll ans = ct[p] + ct[q];

        if(lcm < N) ans -= ct[lcm];

        cout << ans << endl;
    }

    return 0;
}