class Solution {
public:
    int dp[205][20005];

    bool solve(int i, int sum, vector<int> &nums) {
        if (sum == 0)
            return true;
        if (i < 0 || sum < 0)
            return false;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        bool flag = solve(i - 1, sum, nums);
        if (sum - nums[i] >= 0)
            flag |= solve(i - 1, sum - nums[i], nums);
        return dp[i][sum] = flag;
    }

    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;
        sum /= 2;
        return solve(nums.size() - 1, sum, nums);
    }
};

//https://leetcode.com/problems/partition-equal-subset-sum/description/?source=submission-noac