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
const int M = 1e7 + 7;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
const double PI = 3.141592653589793;

ll binExp( ll a , ll b){
	a %= M ;
	ll res = 1 ;
	while(b>0)
	{
		if(b&1) res = (res*a) % M ;
		a = (a*a) % M ;
		b >>= 1 ; 
	}
	return res ;
}

int main()
{
	
	ll n , k;
	while(cin >> n >> k){
		if(n==0 && k==0) return 0;
		ll res = (binExp(n,k) + 2*binExp(n-1,k) + binExp(n,n) + 2*binExp(n-1,n-1)) % M ;
		cout << res << endl;
	}
	
	return 0;
}