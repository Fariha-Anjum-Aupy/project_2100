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

int n;
vector<int> a, new_arr;
int dp[N];

int lis(int i){
    if(dp[i] != -1) return dp[i];
    int length = 1;
    for(int j =0; j < i; j++){
        if(new_arr[j] < new_arr[i]){
            length = max(length, lis(j)+1);
        }
    }
    return dp[i] = length;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        cin >> n;
        a.resize(n);
        new_arr.resize(n * n);
        memset(dp, -1, sizeof(dp));

        f(i, 0, n) cin >> a[i];

        f(i, 0, n*n) new_arr[i] = a[i % n];

        int ans = 0;
        f(i, 0, n*n) ans = max(ans, lis(i));

        cout << ans << endl;
    }
    
    return 0;
}