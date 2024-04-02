class Solution {
public:
    int accountBalanceAfterPurchase(int x) {
    
    int r= std::round(x / 10.0) * 10;
    int ans = 100 - r;
        return ans;
    }
};