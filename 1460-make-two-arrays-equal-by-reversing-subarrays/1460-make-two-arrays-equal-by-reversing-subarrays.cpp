class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int>mp;
        int n = arr.size();
        if(target.size()!=arr.size()){
            return false;
        }
        for(int i : arr){
            mp[i]++;
        }
        for(int t : target){
            if(mp.find(t)==mp.end()||mp[t]==0){
                return false;
            }
            mp[t]--;
        }
        return true;
    }
};