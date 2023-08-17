class Solution {
public:
    bool isPalindrome(int x) {
        int n=x;
        if(x<0){
            return false;
        }
        long long int num=0;
        while(x){
            num=num*10;
            num+=x%10;
            x=x/10;
        }
        if(num==n){
            return true;
        }
        return false;
    }
};