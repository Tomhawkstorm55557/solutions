class Solution {
public:
    bool isPossible(vector<int> position,int mid,int m,int n)
    {
        int preBall=position[0],ball=1;
        for(int i=1;i<n;i++)
        {
            if(position[i]-preBall>=mid)
            {
                preBall=position[i];
                ball++;
            }
        }
        if(ball>=m)
            return true;
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int low=1,high=position[n-1],mid;
        int res=-1;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(isPossible(position,mid,m,n))
            {
                res=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return res;
    }
};