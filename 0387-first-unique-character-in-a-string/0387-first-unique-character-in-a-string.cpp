class Solution {
public:
    int firstUniqChar(string s) {
        queue<int>st;
     int   arr[26]={0};
     for(int i =0;i<s.size();i++){
         char ch = s[i];
         st.push(i);
         arr[s[i]-'a']++;
         while(!st.empty()){
             if(arr[s[st.front()]-'a']>1){
                 st.pop();
             }
             else{
                 break;
             }
             
         }
         
     }   
           if(st.empty())
            return -1;
        return st.front(); 
   
    }
};