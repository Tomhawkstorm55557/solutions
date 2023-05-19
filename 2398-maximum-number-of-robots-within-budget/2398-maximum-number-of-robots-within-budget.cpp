class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
          int j =0;
        long long sum = 0;
        int ans = 0;
        deque<int>dq;
        for(int i=0;i<chargeTimes.size();i++)
        {   
            sum+=runningCosts[i];
            while(!dq.empty() && dq.back()<chargeTimes[i]) 
            { 
                dq.pop_back();
            } 
            dq.push_back(chargeTimes[i]); 
            long long totalcost = sum*(i-j+1) + dq.front();
            
            while(totalcost>budget)
            {
               sum-=runningCosts[j];
               if(dq.front()==chargeTimes[j])
               {
                   dq.pop_front();
               }
                 totalcost = sum*(i-j+1) + dq.front();
                j++;
            }
            
            ans = max(ans, i-j+1);
            
        }
        return ans;
    }
};