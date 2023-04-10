class Solution {
    unordered_map<int,int> dp;
    int sol(int n){
        if(n <= 1) return n;
        if(dp.find(n) != dp.end()) return dp[n];
        int op1 = (n%2) + sol(n/2);
        int op2 = (n%3) + sol(n/3);
        return dp[n] = min({op1,op2}) + 1;
    }
public:
    int minDays(int n){
        return sol(n);
    }
};