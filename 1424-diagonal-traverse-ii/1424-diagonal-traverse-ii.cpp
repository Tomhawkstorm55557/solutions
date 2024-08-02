class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>>grp;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j =0;j<nums[i].size();j++){
                int col = i + j;
               // cout<<"the first point of row"<<" "<<i<<endl;
            
                //cout<<"the second point of column"<<" "<<j<<endl;
            
            
                grp[col].push_back(nums[i][j]);
            }
        }
        
        vector<int>ans;
        int tmp=0;
        while(grp.find(tmp)!=grp.end()){
            for(int t:grp[tmp]){
                ans.push_back(t);
            }
            tmp++;
}
        return ans;
    }
};