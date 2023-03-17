class Solution {
public:
    vector<vector<int>>ans;
   void fun(int r,int l,vector<int>& nums){
        if(l == nums.size()){
            ans.push_back(nums);
        }
        for(int i =l;i<=r;i++){
            swap(nums[i],nums[l]);
            fun(r,l+1,nums);
            swap(nums[i],nums[l]);
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        fun(nums.size()-1,0,nums);
        return ans;
        
    }
};