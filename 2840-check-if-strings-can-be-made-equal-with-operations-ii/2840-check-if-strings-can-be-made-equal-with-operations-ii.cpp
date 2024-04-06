class Solution {
public:
    bool checkStrings(string s1, string s2) {
         if(s1==s2)
            return true;
        
        unordered_map<char,int> evens1, odds1, evens2, odds2;
        int n = s1.size();
		
		//count the frequency of characters at even and odd places separately for both the strings
        for(int i=0;i<n;i++)
        {
            if(i%2==0)//even place
            {
                evens1[s1[i]]++;
                evens2[s2[i]]++;
                
            }
            else // odd place
            {
                odds1[s1[i]]++;
                odds2[s2[i]]++;
            }
        }
		
		//if the frequency map for even and odd places for both the strings is equal simultaneously then strings will be equal after swapping  operation otherwise not
        return (evens1== evens2 && odds1 ==odds2)?true:false;
    }
};