class Solution {
public:
    string largestMerge(string w1, string w2) {
        string ans;
        int i =0,j=0;
        while(i<w1.size()&&j<w2.size()){
            if(w1.compare(i,w1.size()-1,w2,j,w2.size()-1)>0){
                ans+=w1[i++];
            }
            else{
                ans+=w2[j++];
            }
        }
        return ans + w1.substr(i) +w2.substr(j);
    }
};