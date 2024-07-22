class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& height) {
        unordered_map<int,string>mp;
        int n = names.size();
        for(int i =0;i<n;i++){
            mp[height[i]] = names[i];
        }
        sort(height.begin(),height.end(),greater<int>());
        vector<string>ans(n);
        for(int i = 0;i<n;i++){
            ans[i] = mp[height[i]];
        }
        return ans;
    }
};