class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        
        if (m == 0 || n == 0) return {}; // Early return if one of the arrays is empty
        
        set<pair<int, int>> st; // To track the pairs we've already visited
        vector<vector<int>> ans; // To store the result pairs
        
        // Min-heap to store pairs based on their sum
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> mhp;
        
        // Start with the smallest pair
        mhp.push({nums1[0] + nums2[0], {0, 0}});
        st.insert({0, 0});
        
        while (k-- > 0 && !mhp.empty()) {
            auto top = mhp.top();
            mhp.pop();
            
            int i = top.second.first;
            int j = top.second.second;
            ans.push_back({nums1[i], nums2[j]});
            
            // Push the next element in the row
            if (i + 1 < m && st.find({i + 1, j}) == st.end()) {
                mhp.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                st.insert({i + 1, j});
            }
            
            // Push the next element in the column
            if (j + 1 < n && st.find({i, j + 1}) == st.end()) {
                mhp.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                st.insert({i, j + 1}); // Corrected the closing brace error here
            }
        }
        
        return ans;
    }
};