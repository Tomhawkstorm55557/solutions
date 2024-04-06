class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n =4;
        for(int i =0;i<n;i++){
            int j = i + 2;
            if(s1[i]!=s2[i]){
                if(s2[i]==s1[j]){
                    swap(s1[i],s1[j]);
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};