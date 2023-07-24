class Solution {
public:
    double solve(double x, long long n){
        // ans kya kya ho sakta haa -ve 0 , +ve 
        // 1case --> zero vala 
        if(n==0){
            return 1;
        }
    // 2case  ---> -ve
        if(n<0){
            return 1.0/solve(x,-1*n);
        }
        if(n%2==1){
            // agar odd  haaa n 
            return x*solve(x*x,(n-1)/2);
        }
        else{
           return solve(x*x,(n)/2);
        }
        //3 case ---> negative vala
   
    }
    double myPow(double x, int n) {
        return solve(x,(long long)n);
        
    }
};