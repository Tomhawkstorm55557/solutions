class Solution {
public:
    //Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order
    //.Input: nums = [1,2,2]
//Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
    /// this is the staandard backtracking template
    void backie(vector<int>&curr,vector<vector<int>>&ans,int index,vector<int>&nums ){
        ans.push_back(curr);
        for(int i = index;i<nums.size();i++){
            /// duplicate cdtn 
            if(i!=index&&nums[i]==nums[i-1]){
                continue;
            }
            
        
        curr.push_back(nums[i]);
        backie(curr,ans,i+1,nums);
        curr.pop_back();
        }
        
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     //// we will solve using backtracking 
        sort(nums.begin(),nums.end());
        vector<int>curr;
        vector<vector<int>>ans;
        backie(curr,ans,0,nums);
        return ans;
        
    }
};