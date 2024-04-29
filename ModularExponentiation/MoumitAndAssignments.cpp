#include<iostream>
#include <bits/stdc++.h>
#define f(i,s,e) for(long long int i = s; i < e; i++)
#define cf(i,s,e) for(long long int i = s; i <= e; i++)
#define rf(i,e,s) for(long long int i = e-1; i >= s; i--)
#define pb push_back
#define eb emplace_back
#define py cout << "Yes" << endl
#define pn cout << "No" << endl

using namespace std;
const int N = 1e5 + 10;
const long long M = 2760727302517LL;
const int INF = 1e9 + 10;
const double PI = 3.141592653589793;


int t, n, q;
int type, x, v;
ll sum, square_sum;
ll a[N];

long long power(long long a, long long b){
    if(b == 0)
        return 0;
    if(b & 1)
        return (power(a, b - 1) + a) % M;
    long long half = power(a, b >> 1);
    return (half + half) % M;
}

void add(int x, long long v){
    v %= M;
    sum = (sum + M - a[x]) % M;
    sum = (sum + v) % M;
    square_sum = (square_sum + M - power(a[x], a[x])) % M;
    square_sum = (square_sum + power(v, v)) % M;
    a[x] = v;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    for(int c = 1; c <= t; c ++){
        cin >> n >> q;

        for(int i = 1; i <= n; i ++) cin >> a[i];
        
        sum = 0, square_sum = 0;
        for(int i = 1; i <= n; i ++){
            sum = (sum + a[i]) % M;
            square_sum = (square_sum + a[i] * a[i]) % M;
        }
        
        cout << "Case " << c << ":" << endl;
        
        while(q --){
            cin >> type;
            if(type == 1){
                cin >> x >> v;
                add(x, v);
            }
            else if(type == 2){
                cin >> x >> v;
                add(x, a[x] + v);
            }
            else{
                ll result = (n * square_sum % M - power(sum, sum) + M) % M;
                cout << result << endl;
            }
        }
    }
    
    return 0;
}