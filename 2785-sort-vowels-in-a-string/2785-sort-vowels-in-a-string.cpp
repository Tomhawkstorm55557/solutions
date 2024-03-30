class Solution {
public:
      bool is(char c) {
        return c == 'a' || c == 'e' || c == 'o'|| c == 'u'|| c == 'i' 
            || c == 'A' || c == 'E' || c == 'O'|| c == 'U'|| c == 'I';
    }
    string sortVowels(string s) {
     /// finding and storing vowels
        string tm;
        for(char c:s){
            if(is(c)){
                tm+=c;
            }
        }
        int n = s.size();
        sort(tm.begin(),tm.end());
        int j =0;
        string ans;
        for(int i =0;i<n;i++){
            if(is(s[i])){
                ans+=tm[j];
                j++;
                    
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};