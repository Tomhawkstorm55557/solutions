class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		int n=nums.size();
		if(n%2==0) return true;
		vector<vector<int>> dp(n,vector<int>(n,0));
		for(int k=0;k<n;k++) dp[k][k]=nums[k];
		for(int i=n-3;i>=0;i--){
			for(int j=i+1;j<n;j++){
				if(j-2<0) continue;
				int a = nums[i] + min(dp[i+2][j],dp[i+1][j-1]);
				int b = nums[j] + min(dp[i+1][j-1],dp[i][j-2]);
				dp[i][j]=max(a,b);
			}
		}
		int p1=dp[0][n-1];  
		int p2=accumulate(nums.begin(),nums.end(),0)-p1;
		return p1>=p2;
	}
};