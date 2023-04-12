class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
           int start=0;
    int len=INT_MAX;
    
    int n=arr.size();
    
    int sum=0;
    int res=INT_MAX;
    
    vector<int> dp(n,INT_MAX);
    
    for(int end=0;end<n;end++)
    {
        sum+=arr[end];
        
        while(sum>target)
        {
            sum-=arr[start];
            start++;
        }
        
        if(sum==target)
        {
            int curlen=end-start+1;
            
            if(start>0  &&   dp[start-1]!=INT_MAX)
            {
                res=min(curlen+dp[start-1],res);
            }
            
            len=min(curlen,len);
        }
        
        dp[end]=len;
        
    }
    
    if(res==INT_MAX)
        return -1;
    
    
    return res;
    
}
};
      