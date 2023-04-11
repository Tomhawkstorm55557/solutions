class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        int i =0,j=0;
        while(j!=n){
            if(s[j]=='*'){
                i--;
            }
            else{
                s[i++]=s[j];
            }
            j++;
        }
        return s.substr(0,i);
    }
};