class Solution {
public:
    bool ispossible(int k,int ind,vector<int>&nums,vector<vector<int>>&dp){
        //base cases
        if(k==0){
            return true;
            
        }
        if(ind ==0){
            return k==nums[0];
        }
        //memoisation
        if(dp[ind][k]!=-1){
            return dp[ind][k];
        }
        bool pick = false;
        bool no=ispossible(k,ind-1,nums,dp);
        if(nums[ind]<=k){
            pick=ispossible(k-nums[ind],ind-1,nums,dp);
        }
        return dp[ind][k]=pick||no;
    }
    bool canPartition(vector<int>& nums) {
         int n = nums.size();
        int sum =0;
        int target =0;
        for(int i =0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        else{
            target = sum/2;
        }
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return ispossible(target,n-1,nums,dp);
    }
};