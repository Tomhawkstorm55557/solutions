class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      priority_queue<pair<int,int>> maxh;
      int n=arr.size();
      for(int i=0;i<n;i++){
        int a=abs(arr[i]-x);
        maxh.push({a,arr[i]});
        if(maxh.size()>k) maxh.pop();
      }  
      vector<int> ans;
      while(maxh.size()>0){
        ans.push_back(maxh.top().second);
        maxh.pop();
      }
      sort(ans.begin(),ans.end());
      return ans;
    }
};