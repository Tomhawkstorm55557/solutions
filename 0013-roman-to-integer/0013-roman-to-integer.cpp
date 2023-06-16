class Solution {
public:

    int romanToInt(string s) {
        int ans = 0;
        int i = 0;
        map <char, int> mp {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
    };

    while(i < s.size()) {
        if(i==s.size()-1) {
            ans += mp[s[i]];
            break;
        }
        if(mp[s[i]]>=mp[s[i+1]])
                ans += mp[s[i]];
            else
                ans -= mp[s[i]];
        ++i;
    }
    return ans;
    }
};