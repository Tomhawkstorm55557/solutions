class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> s;
        int r = 0;
        for (string &word : words) {
            sort(word.begin(), word.end());
            r += !s.insert(word).second;
        }
        return r;  
    }
};