#define mod 1000000007
class Solution {
public:
    long long dp[109][109];
    long long helper(int length,int unique,int k,int goal,int n){
        if(dp[length][unique]!=-1){
            return dp[length][unique];
        }
        // base case
        if(length ==goal){
            return unique ==n;
        }
        // game shuru babyy
        //pick vala vhi song langa jo pahela liya thaa
        // non pick vala ma alag langa
        long long pick=(helper(length+1,unique+1,k,goal,n)*(n-unique))%mod;
        long long unpick  =  (helper(length+1,unique,k,goal,n)*max(0,unique-k))%mod;
        //final step
        return dp[length][unique]=(pick+unpick)%mod;
    }
   int numMusicPlaylists(int n, int goal, int k) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,k,goal,n);
    }
};