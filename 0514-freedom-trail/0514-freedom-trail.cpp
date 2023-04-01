class Solution {
public:
        vector<vector<int>>dp;
    int solve(string& ring, string &key,int ptr,int index){
        int n = ring.size();
        int  m= key.size();
        //base case
        if(m<=index){
            return 0;
        }
        if(dp[index][ptr]!=-1){
            return dp[index][ptr];
        }  
        int steps = 1e9;
        for(int i =0;i<n;i++){
            if(key[index]==ring[i]){
            steps= min(steps,min(abs(i-ptr),n-abs(i-ptr))+1+solve(ring,key,i,index+1));
            }
        }
        return dp[index][ptr]= steps;
    }
    int findRotateSteps(string ring, string key) {
     
    int n= ring.size();
    int m = key.size();
        int index =0;
        int ptr =0;
        
     dp.assign(m+1,vector<int>(n+1,-1));
        return solve(ring,key,ptr,index);
        
        
    }
};