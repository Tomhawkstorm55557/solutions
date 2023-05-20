class Solution {
public:
    int solve(vector<int>& coins,int amt,vector<int>&dp){
        //base cntd
        if(amt==0){
            return 0;
        }
        if(amt<0){
            return INT_MAX;
        }
        if(dp[amt]!=-1){
            return dp[amt];
        }
        int mi = INT_MAX;
        for(int i =0;i<coins.size();i++){
            //dubra recursion call karoo
         int ans = solve(coins,amt-coins[i],dp);
           /// agar shi haa toh
            if(ans!=INT_MAX){
                mi = min(mi,ans+1);
            }
        }
               dp[amt]=mi;
               return mi;
        
    }
    int coinChange(vector<int>& coins, int amt) {
     int n = coins.size();
    
     vector<int>dp(amt+1,-1);
      int ans = solve(coins,amt,dp);
        if(ans==INT_MAX){
            return -1;
        }
           return ans;
    }
};