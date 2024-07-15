class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() < 2) return nums.size();
        int a , b =1;
        int n = nums.size();
        for(int i =0;i<n-1;i++){
            /// case 1 
            if(nums[i+1]>nums[i]){
              b =   a+1;
              
            }
            else if(nums[i+1]<nums[i]){
                a = b+1;
        
            }
            
        }
      
        return max(a,b);
    }
};