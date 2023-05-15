class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        
        if(s.size()==0){
            return 0;
        }

        int ans =0 ;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
              if(st.empty()){
                  st.push(i);
              }
                else{
                   int  len  = i -st.top();
                    ans = max(len,ans);
                }
            }
        }
        return ans;
    }
};