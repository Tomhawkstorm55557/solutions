class Solution {
public:
    vector<int> grayCode(int n) {
        int value;
        vector<int>ans;
        for(int i =0;i<(1<<n);i++){
            //using formula
            value = i^(i>>1);
            ans.push_back(value);
        }
        return ans;
        
    }
};