class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        ///------>>>>using hashmap 
        map<int,int>mp;
        vector<int>res;
        for(auto i:nums1){
            mp[i]++;
        }
        for(auto i:nums2){
            if(mp[i]>0){
              
                mp[i]--;
                res.push_back(i);
            }
        }
        return res;
    }
};