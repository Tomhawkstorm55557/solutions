class Solution {
public:
   int dp[50001][2];
   int solve(vector<int>& nums, int idx, int n, bool turn)
    {
       if(idx>=n)
        return 0;

        if(dp[idx][turn]!=-1)
        return dp[idx][turn];

       if(turn)
       {
           int ans = INT_MIN;
           int cnt = 0;
           int sum = 0;
           for(int i=idx; i<n && cnt<3; i++)
           {
               sum+=nums[i];
               ans = max(ans,sum+solve(nums,i+1,n,false));
               cnt++;
           }
           return dp[idx][turn] = ans;
       }
       else
       {
           int ans = INT_MAX;
           int cnt = 0;
           int sum = 0;
           for(int i=idx; i<n && cnt<3; i++)
           {
               sum+=nums[i];
               ans = min(ans,solve(nums,i+1,n,true)-sum);
               cnt++;
           }
           return dp[idx][turn] = ans;
       }
    }
    string stoneGameIII(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(nums,0,nums.size(),true); 
        if(ans==0)
        return "Tie";
        else if(ans<0)
        return "Bob";
        else
        return "Alice";
        
    }
};