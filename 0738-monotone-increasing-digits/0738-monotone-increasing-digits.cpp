class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int i =1;
        int n = s.size();
        ///case 1 - jab manotonic haa
        while(s[i]>=s[i-1]&&i<n){
            i++;
            
        }
        if(i<n)
        // case 2->> jab nhi haa
        while(i>0&&s[i-1]>s[i]){
          i--;
           s[i]--; 
        }
        //aab jo bacchi ha string usa 9 bana denga
        for(int j = i+1;j<n;j++){
            s[j] = '9';
        }
          return stoi(s);
        
        
    }
};