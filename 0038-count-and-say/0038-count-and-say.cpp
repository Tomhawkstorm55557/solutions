class Solution {
public:
    string countAndSay(int n) {
         if(n == 1) {
            string str = "";
            str += '1';
            return str;
        }
        string ans = countAndSay(n-1);
        string str ="";
       
        for(int i =0;i<ans.size();i++){
            int count =1;
            while(i!=ans.size()-1&&ans[i]==ans[i+1]){
                
                count++;
                i++;
            }
             str += (count + '0');
            str+=ans[i];
        }
        
        
         return str;
        
    }
};