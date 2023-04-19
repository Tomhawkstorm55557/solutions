class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        for(int i =1;i<n;i++){
            if(security[i-1]>=security[i]){
                prefix[i] = prefix[i-1]+1;
            }
        }
        for(int i =n-2;i>=0;i--){
          if(security[i+1]>=security[i]){
              suffix[i] = suffix[i+1] +1;
          }
        }
        vector<int>ans;

        for(int i=time;i<n-time;i++){
            if(prefix[i]>=time && suffix[i]>=time){
                ans.push_back(i);
            }
        }

        return ans;
    }
};