class Solution {
public:
    string removeOuterParentheses(string s) {
        //is ka ander bhar vala hantanaa haa
        stack<char>st;
        string ans ="";
        int n = s.size();
        for(int i =0;i<n;i++){
            if(st.empty()&&s[i]=='('){
                st.push('(');
            }
            else{
                if(st.size()>0&&s[i]=='('){
                    st.push('(');
                    ans+='(';
                    
                }
                else if(st.size()>1&&s[i]==')'){
                    ans+=')';
                    st.pop();
                }
                else{
                    st.pop();
                }
        }
        }
            return ans;
    }
};