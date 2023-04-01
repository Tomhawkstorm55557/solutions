


class Solution {
public:
    int numberOfWays(string corridor) {
        
        vector<int> seats;
        int n = corridor.size();
        long long ans = 1, mod = 1e9+7;
        
        for(int i = 0; i < n; i++) {
            if(corridor[i] == 'S') seats.push_back(i);
        }
        
        if(seats.size() % 2 == 1 or seats.size() == 0) {
            return 0;
        }
        
        for(int i = 2; i <= seats.size()-2; i += 2) {
            ans = (ans % mod * (seats[i] - seats[i-1]) % mod) % mod;
        }
        
        return (int)ans;
    }
};