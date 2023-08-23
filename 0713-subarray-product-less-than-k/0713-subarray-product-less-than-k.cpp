class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k<=1){
            return 0;
        }
        int prod=1,cnt=0,j=0;
        for(int i =0;i<n;i++){
            prod*=nums[i];
      
            while(prod>=k){
                prod/=nums[j++];
            }
            if(prod<k){
                cnt+=i-j+1;
            }
            
        }
        return cnt;
    }
};