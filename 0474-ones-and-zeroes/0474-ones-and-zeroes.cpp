class Solution {
public:
    vector<vector<vector<int>>>dp;
    int findMaxForm(vector<string>& strs, int m, int n) {
        // making a 3d dp 
     
         
          dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(strs.size(),-1)));
        return findmax(strs,m,n,0);
            
    }
    int findmax(vector<string>&strs,int m,int n ,int index){
        // first base case
        if(index == strs.size()){
            return 0;
        }
        // second dp 
        if(dp[m][n][index]!=-1){
            return dp[m][n][index];
        }
      int  countzeros=count(strs[index].begin(),strs[index].end(),'0');
       int countones = strs[index].size() - countzeros;
        
        
        // 
        if(m-countzeros>=0&&n-countones>=0){
            return dp[m][n][index]=max( 1 + findmax(strs,m-countzeros,n-countones,index+1),findmax(strs,m,n,index+1));
            
        }
                return dp[m][n][index]=findmax(strs,m,n,index+1);                       
    }
};