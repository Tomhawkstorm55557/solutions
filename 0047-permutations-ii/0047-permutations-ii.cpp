class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        for (auto i : nums) {
            mp[i]++;
        }
        vector<int> comb;
        backtrack(mp, ans, nums.size(), comb);
        return ans;
    }

private:
    void backtrack(unordered_map<int, int>& mp, vector<vector<int>>& ans, int n, vector<int>& comb) {
        if (comb.size() == n) {
            ans.push_back(comb);
            return;
        }
        for (auto& i : mp) {
            int fi = i.first;
            int sec = i.second;
            if (sec == 0) {
                continue;
            }
            comb.push_back(fi);
            mp[fi]--;
            backtrack(mp, ans, n, comb);
            comb.pop_back();
            mp[fi]++;
        }
    }
};
