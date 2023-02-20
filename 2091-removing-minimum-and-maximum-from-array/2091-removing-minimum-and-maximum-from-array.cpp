class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
   int mini = min_element(nums.begin(),nums.end())-nums.begin();
   int maxi = max_element(nums.begin(),nums.end())-nums.begin();     
    
        //jab from start index sa karenga
        int mthd1 = max(mini,maxi)+1;
     // jab last sa karenga
        int mthd2 = nums.size() -min(mini,maxi);
         int cnt = min(mthd1,mthd2);
        //jab dono sa start karenfa
         int mthd4 =min(mini,maxi)+1+nums.size()-max(mini,maxi);
        return min(mthd4,cnt);
    }
};