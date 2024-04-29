int dp[1005];
int solve(int len, vector<int> &prices){
    if(len == 0) return 0;
    if(dp[len] != -1) return dp[len];
    int ans = 0;
    for(int i = 1; i <= prices.size(); i++){
        if(len - i >= 0){
            ans = max(ans, solve(len-i, prices) + prices[i-1]);
        }
    }
    return dp[len] = ans;
}

int cutRod(int price[], int n){
    memset(dp, -1, sizeof(dp));
    vector<int> prices(price, price+n);
    return solve(n, prices);
}

//https://www.geeksforgeeks.org/problems/rod-cutting0840/1