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

ll dp[105][100005];
int wt[105], val[105];

ll knapsack(int ind, int wt_left){
    if(wt_left == 0) return 0;
    if(ind < 0) return 0;
    if(dp[ind][wt_left] != -1) return dp[ind][wt_left];
    ll ans = knapsack(ind-1, wt_left);

    if(wt_left - wt[ind] >= 0)
    ans = max(ans, knapsack(ind-1, wt_left - wt[ind]) + val[ind]);
    return dp[ind][wt_left] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof(dp));
    int n, w;
    cin >> n >> w;

    for(int i = 0; i < n; i++){
        cin >> wt[i] >> val[i];
    }

    cout << knapsack(n-1, w) << endl;

    return 0;
}