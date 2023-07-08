class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count =0;
        for(int x=0; x<strs[0].length(); x++) 
        {
            for(int i=1; i<strs.size(); i++)
            {
                if(x==strs[i].length() || strs[0][x]!=strs[i][x]) goto here;
            }
            count++;
        }
        
        here:
        return strs[0].substr(0,count);
    }
};