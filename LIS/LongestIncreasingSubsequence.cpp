class Solution {
public:
    int dp[2515];

    int lis(int i, vector<int>& a) {
        if (dp[i] != -1)
            return dp[i];
        int length = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                length = max(length, lis(j, a) + 1);
            }
        }
        return dp[i] = length;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, lis(i, nums));
        }
        return ans;
    }
};