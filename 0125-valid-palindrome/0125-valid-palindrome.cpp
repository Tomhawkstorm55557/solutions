class Solution {
public:
    bool isPalindrome(string s) {
    int r = s.size()-1; 
    int l =0;
     while(r>l){
         if ( ! isalpha( s[l] ) && ! isdigit( s[l] ) ) l++;
        else if(! isalpha( s[r] ) && ! isdigit( s[r] ) ) r--;
        else if ( tolower(s[l++]) != tolower(s[r--]) ) return false;
     }   
        return true;
    }
};