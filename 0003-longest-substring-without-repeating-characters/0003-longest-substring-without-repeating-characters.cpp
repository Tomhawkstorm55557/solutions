class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        ////dp socho
        int ans = 0;
        int st =0;
      unordered_map<char,int>mp;
     
        for(int i =0;i<n;i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]] =i;
}        
            else{
                st = max(st,mp[s[i]]+1);
                mp[s[i]] =i;
}
            ans = max(ans,i-st+1);
        }
        return ans;
        
    }
};