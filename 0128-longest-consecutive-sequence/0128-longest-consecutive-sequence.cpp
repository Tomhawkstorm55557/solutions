class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans =0;
        /// using sets
        unordered_set<int>s(nums.begin(),nums.end());
        int n = nums.size();
           int maxl =1;
        // base cndtn 
         if(n <= 1)
    {
        return n;
    }
        
        for(int i =0;i<n;i++){
            int len = 1 ; 
         
            // case 1--> agar isaa pahela vala eist karta ha 
            if(s.find(nums[i]-1)!=s.end()){
                continue;
            }
            ///case 2 --> 
            int curr = nums[i];
              while(s.find(curr + 1) != s.end()){
                  curr++;
                  len++;
              }
                 maxl = max(maxl, len);
        }
        return maxl;
        
    }
};