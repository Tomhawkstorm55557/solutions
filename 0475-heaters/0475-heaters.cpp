class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heater) {
        sort(heater.begin(),heater.end());
        int ans =0;
        //houses shuru karooo
        for(int i =0;i<houses.size();i++){
            //yaha sa binary search lagana shuru karpoo
            int radius =INT_MAX;
            int start =0;
            int end = heater.size()-1;
            //applying binary search
            while(start<=end){
             int   mid = start + (end-start)/2;
                if(houses[i]==heater[mid]){
                    radius=0;
                    break;
                }
                else{
                  int diff=abs(houses[i]-heater[mid]);
                
                   radius=min(diff,radius);
                             //
                  if(houses[i]>heater[mid]){
                      start = mid+1;
                  }
                    else if(houses[i]<heater[mid]){
                        end = mid-1;
                    }
                }
            }
            ans= max(ans,radius);           
        }
        return ans ;
        
    }
};