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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll digitSum(ll n){
    ll sum = 0;
        while(n){
            sum += n%10;
            n /= 10;
        }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        ll ds = digitSum(n), ans = n;
        ll check = gcd(n, ds);

        while(check == 1){
            ans++;
            ds = digitSum(ans);
            check = gcd(ans, ds);
        }

        cout << ans << endl;
    }
    return 0;
}