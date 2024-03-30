class Solution {
public:
    long long helper(int ind, vector<int>& nums, int x, int parity, vector<vector<long long>>& dp) {
// IF WE GO BEYOND ARRAY THEN RETURN 
        if (ind == nums.size())
            return 0;

        if (dp[ind][parity] != -1)
            return dp[ind][parity];

        long long take = nums[ind] + helper(ind + 1, nums, x, nums[ind] % 2, dp);
// IF TAKEN CHECK IF IT HAS DIFFERENT PARITY OF NOT
        if (nums[ind] % 2 != parity)
            take -= x;

        long long notTake = helper(ind + 1, nums, x, parity, dp);

        return dp[ind][parity] = max(take, notTake);
    }

    long long maxScore(vector<int>& nums, int x) {
        vector<vector<long long>> dp(nums.size(), vector<long long>(2, -1));
        return helper(0, nums, x, nums[0] % 2, dp);
    }
};