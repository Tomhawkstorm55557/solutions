class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> index_map;
        for (int i = 0; i < target.size(); ++i) {
            index_map[target[i]] = i;
        }
        
        vector<int> lis;
        
        for (int num : arr) {
            if (index_map.find(num) != index_map.end()) {
                int idx = index_map[num];
                auto it = lower_bound(lis.begin(), lis.end(), idx);
                if (it == lis.end()) {
                    lis.push_back(idx);
                } else {
                    *it = idx;
                }
            }
        }
        
        return target.size() - lis.size();
    }
};
