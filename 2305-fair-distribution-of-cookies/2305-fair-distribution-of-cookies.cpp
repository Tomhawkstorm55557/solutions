class Solution {
public:
    int ans =INT_MAX;
  void backtrack(vector<int>& cookies,int k,int indx,vector<int>&v){
        if(indx>=cookies.size()){
            int res = INT_MIN;
        for(int i =0;i<k;i++){
        
            res=max(res,v[i]);
            
            
        }
            ans = min(ans,res);
            return ;
    }
    for(int i =0;i<k;i++){
        v[i]+=cookies[indx];
        backtrack(cookies,k,indx+1,v);
        v[i]-=cookies[indx];
    }   
  }    
int distributeCookies(vector<int>& cookies, int k) {
    vector<int> v(k,0);
        backtrack(cookies,k,0,v);
        return ans;
    }
};  
   