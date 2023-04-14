class Solution {
public:
    vector<vector<int>>dp;
    int solve(string&s,int i,int j){
        //base case bound
        if(i>j){
            return 0;
        }
        //memosisation base case
        if(dp[i][j]!=0){
            return dp[i][j];
        }
       int x =i;
        while(x+1<=j&&s[x+1]==s[i]){
            x++;
        }
         
      
          int ans = 1 + solve(s,x+1, j); 
        for(int k = x+1; k<=j; k++){
            if(s[k] == s[i]){
                ans = min(ans, solve(s,k,j) + solve(s,x+1, k-1));
            }
        }
        return dp[i][j] = ans;
    }
    int strangePrinter(string s) {
        
            dp=vector<vector<int>>(s.size(),vector<int>(s.size(),0));
               return solve(s,0,s.size()-1);
    }
};