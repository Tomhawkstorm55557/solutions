class Solution {
public:
    string getHint(string secret, string guess) {
        // geting the size of secret
        int n = secret.size();
  // is vala maa digit same hogi aur same place ma hogi      
        int bulls = 0;
     // creting vectors to store bulls and cows
       vector<int>s(10),g(10);
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                bulls++;
            }
            else{
                // jab voh haa but alag places paa haa
                s[secret[i]-'0']++;
                g[guess[i]-'0']++;
            }
            
        }
        int cows = 0;
        for(int i =0;i<10;i++){
            cows+=min(s[i],g[i]);
        }
            string ans="";
            ans+= to_string(bulls);
            ans+="A";
                
            ans+=to_string(cows);
            ans+="B";
        
        return ans;
        
        
        
    }
};