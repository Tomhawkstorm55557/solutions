class Solution {
public:
    //initializing dp
    //1 <= rods.length <= 20
//1 <= rods[i] <= 1000
//sum(rods[i]) <= 5000
    int dp[21][10003];
    int sol(vector<int>& rods, int i, int diff){
        int n = rods.size();
        //base cases
        if(i==n){
            if(diff==0){
            //agar diff ===0 ha mtlb barabar bata ha
            return 0;
            }
            return INT_MIN;
        }
        // agar pahela he kar chuka ha toh
         if( dp[i][diff+5000] != -1)
            return  dp[i][diff+5000];
        // aab humpa haa teen option us rod ko weld karna kaa
        //1> isko left vala ma add karoo
        //2> isko rht vala ma add karoo
        //3> leave karoo aur dusra dekho
      
       int kuch_nhi    = sol(rods, i + 1 , diff);
        int rod1    = rods[i] + sol(rods, i + 1 , diff + rods[i]);
        int rod2 = rods[i] + sol(rods, i + 1 , diff - rods[i]);

        return dp[i][diff+5000] = max({kuch_nhi, rod1, rod2});
        
    }
    int tallestBillboard(vector<int>& rods) {
       int n = rods.size();
        //filling an dp array
          memset(dp, -1, sizeof(dp));
       return  sol(rods,0,0)/2;
    
    }
};