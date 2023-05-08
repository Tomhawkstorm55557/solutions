class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
      
        vector<int>res(n+1,0);
        
        for(auto it:bookings){
            res[it[0]-1]+=it[2];
            res[it[1]]-=it[2];
        }
        
        for(int i=1;i<n;i++)
            res[i]+=res[i-1];
            res.pop_back();
   
        return res;
    
    }
};