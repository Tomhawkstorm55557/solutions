class Solution {
public:
    int mod = 1e9+7;
    int no_of_routes(  vector<vector<int>>&dp,int& finish,int start,vector<int>& loc,int fuel ){
        int n = loc.size();
        /// base cdtn jab fuel khtam 
        if(fuel<0){
            return 0;
        }
    
        // memo 
        if(dp[start][fuel]!=-1){
            return dp[start][fuel];
        }
        int ans =0;
        //ans cdtb
        if(start==finish){
            ans++;
        }
        /// recursion
        for(int nt =0;nt<n;nt++){
            if(nt!=start){
        ans=(ans%mod+no_of_routes(dp,finish,nt,loc,fuel-abs(loc[start]-loc[nt]))%mod)%mod;
            }
        }
       return dp[start][fuel]=ans%mod;
        
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        // routes nikalana hha choices vala question haa dp 
        //Return the count of all possible routes from start to finish. Since the answer may be too large, return it modulo 109 + 7.
        // 1cdtn--->>>>>  |locations[i] - locations[j]|
        ///2cdtn ---->>>>> Notice that fuel cannot become negative at any point in time, and that you are allowed to visit any city more than once (including start and finish).
        int n = locations.size();
          vector<vector<int>>dp(n,vector<int>(fuel+1,-1));
       return  no_of_routes(dp,finish,start,locations,fuel);
        
    }
};