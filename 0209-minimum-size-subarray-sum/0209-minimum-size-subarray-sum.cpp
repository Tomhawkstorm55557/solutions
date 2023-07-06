class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int sum =0;
        int j =0;
        for(int i =0;i<nums.size();i++){
            
            sum+= nums[i];
            while(sum>=target){
                int len = i-j+1;
                ans = min(ans,len);
                sum-=nums[j];
                j++;
            }
        }
        return ans == INT_MAX?0:ans;
    }
};