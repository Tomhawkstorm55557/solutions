class Solution {
public:
    int compress(vector<char>& chars) {
        string ans;
        int cnt = 1;
             ans.push_back(chars[0]);
        for(int i =1;i<chars.size();i++){
            if(chars[i]==chars[i-1]){
                cnt++;
            }
            else{
                if(cnt>1){
                    ans = ans + to_string(cnt);
                }
                    cnt = 1;
                    ans.push_back(chars[i]);
                
            }
            
        }
        if(cnt>1){
             ans = ans + to_string(cnt);
        }
        for(int j =0;j<ans.length();j++){
            chars[j] = ans[j]; 
        }
        return ans.size();
        
    }
};