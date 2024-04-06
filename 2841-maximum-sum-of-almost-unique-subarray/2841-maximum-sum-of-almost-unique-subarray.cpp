class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        map<int,int> mp;  
        long long sum=0;
        long long ans=-1;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
            sum+=nums[i];
        }
        if(mp.size()>=m){
            ans=max(ans,sum);
        }
        int x=0;
        for(int i=k;i<nums.size();i++){
            
            sum-=nums[x];
            mp[nums[x]]--;
            if(mp[nums[x]]==0) mp.erase(nums[x]);
            sum+=nums[i];
            mp[nums[i]]++;
            
            if(mp.size()>=m){
              ans=max(ans,sum);
                
            }
            
            
            x++;
        }
        
        if(ans==-1) return 0; 
        return ans;
       
    }
};