class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        string st = s+s;
        /// using find 
        return st.find(goal)!= string::npos;
        
    }
};