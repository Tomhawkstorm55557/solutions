class Solution {

public:
    int climbStairs(int n) {
        if(n <= 2)
            return n;

        int n1 = 1, n2 = 2, temp = 0;
        int step = 3;
        while(step <= n) {
            temp = n1 + n2;
            n1 = n2;
            n2 = temp;
            step++;
        }
        return n2;
    }
};
        