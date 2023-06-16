class Solution {
public:


    int singleNumber(vector<int>& nums) {
        int ones =0;
        int two =0;
        for(int num:nums){
            ones = (ones^num)& ~two;
            two = (two^num)&~ones;
        }
        return ones;
        
    }
};