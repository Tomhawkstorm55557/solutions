class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        int st = 0;
        int cnt =0;
        unordered_map<char,bool> mp;
        while(st<n){
            if(mp.find(s[st])!=mp.end()){
                cnt++;
                
                mp.clear();
            }
            mp[s[st]]=true;
            st++;
            
        }
        return cnt+1;
        
    }
};