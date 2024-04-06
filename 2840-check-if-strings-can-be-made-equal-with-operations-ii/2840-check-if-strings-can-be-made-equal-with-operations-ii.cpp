class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if(s1==s2){
            return true;
        }
        unordered_map<char,int>odd1,odd2,even1,even2;
        int n = s1.size();
        for(int i =0;i<n;i++){
            if(i%2==0){
                even1[s1[i]]++;
                even2[s2[i]]++;
            }
            else{
                odd1[s1[i]]++;
                odd2[s2[i]]++;
            }
        }
           return (even1== even2 && odd1 ==odd2)?true:false;
    }
};