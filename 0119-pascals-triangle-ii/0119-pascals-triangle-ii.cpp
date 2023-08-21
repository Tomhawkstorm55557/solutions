class Solution {
public:
    vector<int> getRow(int row) {
        vector<int>ans;
     for(int i =0;i<=row;i++){
         ans.push_back(1);
         for(int j =i-1;j>=1;--j){
         ans[j]    = ans[j]+ans[j-1];
         }
         
     }   
        return ans;
    }
};