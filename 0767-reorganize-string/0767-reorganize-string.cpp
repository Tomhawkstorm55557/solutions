class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }

        string result = "";
        char prev = '#';  // Initialize prev with a character that won't appear in the input

        while (!charCount.empty()) {
            char next = '\0';  // Initialize next with a placeholder value
            for (auto it = charCount.begin(); it != charCount.end(); ++it) {
                if (it->first != prev && (next == '\0' || it->second > charCount[next])) {
                    next = it->first;
                }
            }

            if (next == '\0') {
                return "";  // No valid next character found
            }

            result += next;
            prev = next;
            charCount[next]--;

            if (charCount[next] == 0) {
                charCount.erase(next);
            }
        }

        return result;
    }
};
