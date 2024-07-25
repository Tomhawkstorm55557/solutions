class Solution {
    struct compare {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second > b.second; // Lexicographical order for the same frequency
            }
            return a.first < b.first; // Frequency in descending order
        }
    };

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto& i : words) {
            mp[i]++;
        }

        // Create a priority_queue with the custom comparator
        priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
        for (auto& i : mp) {
            pq.push({i.second, i.first}); // {frequency, word}
        }

        vector<string> ans;
        while (k-- > 0 && !pq.empty()) {
            ans.push_back(pq.top().second); // Get the word
            pq.pop();
        }
        return ans;
    }
};
