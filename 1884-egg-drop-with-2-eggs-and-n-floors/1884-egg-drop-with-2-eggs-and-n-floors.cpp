class Solution {
public:
    int minMove(int egg,int f,vector<vector<int>> &dp){
        if(egg==1){
            return f;
        }

        if(f==0 || f==1) return f;

        if(dp[egg][f]!=-1) return dp[egg][f];

        int mi=INT_MAX;
        for(int i=1;i<f;++i){
            int Break=minMove(egg-1,i-1,dp);
            int notBreak=minMove(egg,f-i,dp);
            int move=1+max(Break,notBreak);
            mi=min(mi,move);
        }

        return dp[egg][f]=mi;
    }

    int twoEggDrop(int n) {
        vector<vector<int>> dp(3,vector<int>(n+1,-1));
        return minMove(2,n,dp);
    }
};