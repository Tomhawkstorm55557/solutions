class Solution {
   
public:
     #define  ll long long
    ///Input: nums = [2,6,7,3,1,7], m = 3, k = 4
    long long maxSum(vector<int>& nums, int m, int k) {
        /// case 1 when n is equal to k 
        map<int,int>mp;
        ll ans = -1;
        ll sum =0;
        for(int i =0;i<k;i++){
            mp[nums[i]]++;
            sum+=nums[i];
        }
          if(mp.size()>=m){
            ans=max(ans,sum);
        }
        int x =0;
        int n = nums.size();
        for(int i =k;i<n;i++){
            mp[nums[x]]--;
            sum-=nums[x];
           if(mp[nums[x]]==0){
               mp.erase(nums[x]);
           }
              mp[nums[i]]++;
            sum+=nums[i];
             if(mp.size()>=m){
            ans=max(ans,sum);
        }
            x++;
        }
           if(ans==-1) return 0; 
        return ans;
    }
};