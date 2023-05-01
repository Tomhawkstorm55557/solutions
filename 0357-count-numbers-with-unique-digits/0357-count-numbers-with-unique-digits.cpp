class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int>dp(n+2);
        dp[0]=1,dp[1]=10;
        int sum=1,curr =9;
        for(int i =2;i<=n;i++){
            dp[i] = dp[i-1]*curr +sum;
            sum+=dp[i-1];
            curr--;
        }
        return dp[n];
    }
};