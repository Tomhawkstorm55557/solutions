class Solution {
public:
    int solve(int i,int j,int &n,int k,vector<vector<int>> &g,vector<vector<int>> &dp){
        if(i<0||j<0||i>=n||j>=n||g[i][j]!=k){
            return 0;
        }
        if(k==(n*n-1)){dp[i][j]= 1;return 1;}
        if(dp[i][j] != -1)return dp[i][j];
        return dp[i][j] =  (solve(i+2,j+1,n,k+1,g,dp) || solve(i+2,j-1,n,k+1,g,dp) || solve(i+1,j-2,n,k+1,g,dp) || solve(i+1,j+2,n,k+1,g,dp) || solve(i-1,j+2,n,k+1,g,dp) || solve(i-1,j-2,n,k+1,g,dp) || solve(i-2,j+1,n,k+1,g,dp) || solve(i-2,j-1,n,k+1,g,dp));
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==1){
            return true;
            
        }
        else if(n==2||n==3){
            return false;
        }
        // if(grid[0][0]==false)return false;
      //  for(int i= 0; i < n; i++){};
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,0,n,0,grid,dp);
        
        return dp[0][0];
    }
};