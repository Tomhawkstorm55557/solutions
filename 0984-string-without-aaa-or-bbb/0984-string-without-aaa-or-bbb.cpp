class Solution {
public:
    string strWithout3a3b(int a, int b) {

        //idea is we count how many continous a's & b's appended if if becomes we change next letter to be appended
        
        string res="";
        int la=0,lb=0;
        while(a>0 || b>0){

            if((a>=b && la<2 )||(b>=a && lb==2)){//we will append a if its greater than b & not creating aaa
                res+="a";
                a--;
                la++;
                lb=0;
            }
            else {
                res+="b";
                b--;
                lb++;
                la=0;
            }

        }
        return res;
        
    }
};