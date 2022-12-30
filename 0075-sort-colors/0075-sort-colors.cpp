class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,f=0,last=nums.size()-1,temp;
        
        while(i<=last)
        {
            if(nums[i]==0)
            {
                temp=nums[i];
                nums[i]=nums[f];
                nums[f]=temp;
                f++;
                i++;
            }
            else if(nums[i]==1)
                i++;
            
            else if(nums[i]==2)
            {
                temp=nums[i];
                nums[i]=nums[last];
                nums[last]=temp;
                last--;
            }
        }
        
    }
};