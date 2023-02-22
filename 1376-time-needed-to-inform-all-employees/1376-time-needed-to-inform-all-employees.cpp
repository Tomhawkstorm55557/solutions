class Solution {
public:
    unordered_map<int , vector<int>>unmap;
    int mxi =0;
    int ans = 0;
    void dfs(int mangers,vector<int>&informTime){
        mxi = max(mxi,ans);
        for(auto employee : unmap[mangers]){
            ans+= informTime[mangers];
            dfs(employee,informTime);
            ans-=informTime[mangers];
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        //making an adjaency list
        for(int i=0;i<n;i++){
         int   val = manager[i];
            if(val!=-1){
                unmap[val].push_back(i);
                
            }
        }
        dfs(headID,informTime);
        return mxi;
    }
};