class Solution {
public:
    int f(long long n){
        if(n ==1){
            return 0;
        }
     int b=INT_MAX,p=INT_MAX,m=INT_MAX;
        if(n%2==0){
         b = 1 + f(n/2);
        }
        else{
			p=1+f(n+1);
			m=1+f(n-1);
		}
        return min(b,min(p,m));

    }
    int integerReplacement(int n) {
        return f(n);
    }
};