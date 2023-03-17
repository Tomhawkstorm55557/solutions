class Solution {
public:
    int ans=0;
    
    void helper(vector<int> &nums, int ind){
        
        if(ind==nums.size()){
            ans++;
            return;
        }
        
        for(int i=ind; i<nums.size(); i++){
            swap(nums[ind], nums[i]);
            if(nums[ind]%(ind+1)==0 || (ind+1)%nums[ind]==0) helper(nums, ind+1);
            swap(nums[ind], nums[i]);
        }
        
    }
    
    int countArrangement(int n) {
        if(n==1) return 1;
        vector<int> nums;
        for(int i=1; i<=n; i++)
            nums.push_back(i);
        
        helper(nums, 0);
        return ans;
    }
};