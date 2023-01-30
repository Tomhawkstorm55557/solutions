class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_gas=0,total_cost=0;
        int curr_gas=0,starting_point=0;
        for(int i=0;i<n;i++){
            total_cost+=cost[i];
            total_gas+=gas[i];
            
            //lets check the gas present
            curr_gas+=gas[i]-cost[i];
            if(curr_gas<0){
                //it means it is not the starting point toh aga badao
                starting_point = i+1;
                // now reset the petrol tank
                curr_gas =0;
            }
            
        }
        return(total_gas<total_cost)?-1:starting_point;
    }
};