class Solution {
public:
    int mod=1e9+7;
    int solve(int n,int x,int num,vector<vector<int>> &dp){
        if(num==0) return 1;
        if(n==1) return num==1;
        if(dp[n][num]!=-1) return dp[n][num];
        int nottake=solve(n-1,x,num,dp);
        int take=0;
          if(num>=pow(n,x)){
             take+=solve(n-1,x,num-pow(n,x),dp);
                    }
           return dp[n][num]=(take+nottake)%mod; 
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(n,x,n,dp);
    }
};