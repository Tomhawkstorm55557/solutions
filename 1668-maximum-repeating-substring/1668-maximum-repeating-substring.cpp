class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string temp =word;
        int cnt =0;
        while(sequence.find(temp)!=string::npos){
            cnt++;
            temp+=word;
        }
        return cnt;
     
    }
};