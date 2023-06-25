class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i =0;i<n;i++){
            int abhi = nums[i];
            // kya yeh pahela thaa
        if(mp.find(abhi)!=mp.end()){
            // haa toh second cdtn check karo
                  if(abs(i-mp[abhi]) <= k){
                      return true;  
                  }
          mp[abhi]=i;  
            
        }
            mp[abhi] = i;
        }
        return false;
    }
};