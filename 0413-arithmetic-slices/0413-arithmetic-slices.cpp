class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
            int n = nums.size();
        vector<int>dp(n);
        int count =0;

        if(n<3){
            return 0;
        }
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
             //So while storing 2nd ans in dp, we'll simply add the previous 1 to our current dp.
//dp[i] = 1 + dp[i-1]
//Add the current dp count to our answer variable, count += dp[i];   
                dp[i] = 1 + dp[i-1];
                count+=dp[i];
            }
        }
        return count;
    }
};