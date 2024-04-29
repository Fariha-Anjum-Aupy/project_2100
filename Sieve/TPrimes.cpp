#include<iostream>
#include <bits/stdc++.h>
#define ll long long int
#define f(i,s,e) for(long long int i = s; i < e; i++)
#define cf(i,s,e) for(long long int i = s; i <= e; i++)
#define rf(i,e,s) for(long long int i = e-1; i >= s; i--)
#define pb push_back
#define eb emplace_back
#define py cout << "YES" << endl
#define pn cout << "NO" << endl

using namespace std;
const int M = 1e9 + 7;
const int N = 1e6 + 10;

vector<bool> isPrime(N, true);
vector<int> hp(N, 0);

void sieve(){
    isPrime[0] = isPrime[1] = false;
    f(i, 2, N){
        if(isPrime[i]){
            for(int j = 2*i; j < N; j += i){
                isPrime[j] = false;
                hp[j] = i;
            }
        }
    }
}

bool check(ll x) {
    ll root = sqrt(x);
    if(root >= N) return false;
    return root * root == x && isPrime[root];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    sieve();

    while(n--){
        ll x;
        cin >> x;

        if(check(x)) py;
        else pn;
    }

    return 0;
}