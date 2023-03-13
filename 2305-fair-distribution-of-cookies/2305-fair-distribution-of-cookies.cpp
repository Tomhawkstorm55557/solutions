class Solution {
public:
    int ans=INT_MAX;
    void backtrack(vector<int>& cookies, int k,vector<int> &v,int idx)
    {
        if(idx>=cookies.size())
        {
            int res=INT_MIN;
            for(int i=0;i<k;i++)
            {
                res=max(res,v[i]);
            }
            ans=min(ans,res);
            return;
        }
        for(int i=0;i<k;i++)
        {
            v[i]+=cookies[idx];
            backtrack(cookies,k,v,idx+1);
            v[i]-=cookies[idx];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) 
    {
        vector<int> v(k,0);
        backtrack(cookies,k,v,0);
        return ans;
        
    }
};