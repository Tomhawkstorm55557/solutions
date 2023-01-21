class Solution {
public:
    int fibo(int n,vector<int>&dp)
    {
        if(n==0) return 0;
        if(n==1) return 1;

        if(dp[n]!=-1)return dp[n];
        return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
    }
    int fib(int n) {
     vector<int>dp(n+1,-1);
     return fibo(n,dp); 
    }
};