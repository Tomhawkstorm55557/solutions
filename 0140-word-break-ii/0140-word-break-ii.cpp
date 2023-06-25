class Solution {
public:
    void senten(int id,string&s,string curr,unordered_set<string>&st,vector<string>&ans){
        /// base cndtn 
        if(id==s.length()){
            
        curr.pop_back();
            ans.push_back(curr); //remove the trailing space
           
        }
        /// sari substring banao aur check karoo kya 
         string len ="";
        for(int i =id;i<s.length();i++){
            len.push_back(s[i]);
            if(st.count(len)){
                senten(i+1,s,curr+len+" ",st,ans);
            }
        }
    }
        
        
        
        
        
        
  vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string>st;
        vector<string>ans ;
        string curr = "";
        // saraa words store kara ta ha set maa
        for(auto words:wordDict){
            st.insert(words);
        }
        /// callling  a function 
        senten(0,s,curr,st,ans);
        return ans;
    }
};