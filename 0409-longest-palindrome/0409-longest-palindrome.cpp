class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        int cnt =0;
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
            if(mp[ch]%2==1){
                cnt++;
            }
            else{
                cnt--;
            }
        }
         
        
               if(cnt>1){
                 return s.length() - cnt + 1;
            }
        return s.length();
    }
};