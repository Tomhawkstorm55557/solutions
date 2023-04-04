
class Solution {
public:
    int findMinMoves(vector<int>& machines) 
    {
        int n= machines.size();
        int sum=0;
		
        for(int i=0; i<n; i++)
        {
            sum += machines[i];
        }
        if(sum % n != 0)
            return -1;
        int req = sum/n;
	
		
        int extra =0, ans=0;
        for(int i=0; i<n; i++)
        {
            extra += machines[i]-req;
            ans = max(ans, max(machines[i]-req, abs(extra)));
        }
        return ans;
    }
};