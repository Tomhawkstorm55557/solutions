class Solution {
public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return {};
        }
        if (n == 1) {
            return nums;
        }

        std::vector<int> dp(n, 1);
        std::vector<int> pre(n, -1);

        std::sort(nums.begin(), nums.end());

        int mx = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
            if (dp[mx] < dp[i]) {
                mx = i;
            }
        }

        std::vector<int> res;
        while (mx != -1) {
            res.push_back(nums[mx]);
            mx = pre[mx];
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
