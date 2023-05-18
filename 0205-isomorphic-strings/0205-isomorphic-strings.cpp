class Solution {
public:
  
  bool solve(string s,string t){
        
    map<char,char>mp;
        
    for(int i=0;i<s.size();i++){
        
        if(mp.find(s[i])!=mp.end()){
            if(mp[s[i]]!=t[i]) 
                return false;
        }
        
        else 
            mp[s[i]]=t[i];   //mapping of character to character
    }
    return true;
}

   bool isIsomorphic(string s, string t) {
       
       if(s.length() != t.length())
           return false;
       
    return (solve(s,t) and solve(t,s));   //we need to check both ways testcase "badc"  "baba"
                                                                                                                   
  }
};
