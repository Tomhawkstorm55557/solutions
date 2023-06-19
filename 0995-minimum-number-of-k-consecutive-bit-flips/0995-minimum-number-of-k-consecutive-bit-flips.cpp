class Solution {
public:
     int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        queue<int> q;
        for(int i=0;i<n;i++)
        {
                if(nums[i]==0)
                {
                  if(q.empty() || q.size()%2==0)
                  {
                    count++;
                          q.push(i+k-1);
                  }
                        
                }
                else
                {
                        if(q.size()%2!=0)
                        {
                                count++;
                                q.push(i+k-1);
                        }
                }
                // k length  window if i >= window's end pop it 
                if(!q.empty() && i>=q.front())
                {
                        q.pop();
                }
        }
        if(q.empty())
        return count;
        else
        {
                return -1;
        }
        
}
};