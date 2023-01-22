class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.size()<ransomNote.size()) return false;
        map<char,int>mp;
         for(int i=0; i<magazine.length(); i++) {
            mp[magazine[i]]++;
        }
        
        for(int i=0; i<ransomNote.length(); i++) {
            if(mp[ransomNote[i]]>0) mp[ransomNote[i]]--;
            else return false;
        }
        
        return true;
        
    }
};