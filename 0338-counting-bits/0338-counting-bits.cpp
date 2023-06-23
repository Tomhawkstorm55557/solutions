class Solution {
    int set_bits(int n) {
        int steps = 0;
        while(n) {
            n = n & (n - 1);
            steps++;
        }
        return steps;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++) {
            ans.push_back(set_bits(i));
        }
        return ans;
    }
};