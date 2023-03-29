class Solution {
    int dp(int in,vector<int>& s,int time,vector<vector<int>>& dpA){
        if(in==s.size())return 0;
        if(dpA[in][time]!=-1)return dpA[in][time];
        // pick
        int pick=INT_MIN,notPick=INT_MIN;
        pick=(time*s[in])+dp(in+1,s,time+1,dpA);
        // not pick
        notPick=dp(in+1,s,time,dpA);
        return dpA[in][time]=max(pick,notPick);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        vector<vector<int>> dpA(satisfaction.size(),vector<int>(satisfaction.size()+1,-1));
        sort(satisfaction.begin(),satisfaction.end());
        return dp(0,satisfaction,1,dpA);
    }
};
