class Solution {
public:

           int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, n = colors.size();
        for (int i = 1; i < n; i++) {
            // if the i-th balloon has the same color as (i - 1)th one
            // e.g. aba[a]c and i = 3 (0-based)
            if (colors[i] == colors[i - 1]) {
                // then we remove the one with less time
                // e.g. in above example, we remove the balloon at index 2 
                // with neededTime[2] since neededTime[2] < neededTime[3] 
                ans += min(neededTime[i], neededTime[i - 1]);
                // update the max neededTime inplace 
                // or alternatively you can store it in a variable
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }
        return ans;
        
    }
};