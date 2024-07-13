class Solution {
public:
    int thirdMax(vector<int>& arr) {
             // Sort the array in non-increasing order.
        sort(arr.begin(), arr.end(), greater<int>());
        int n = arr.size();
     int cnt = 1;
     int pre = arr[0];
        for(int i =0;i<n;i++){
            if(arr[i]!=pre){
                cnt++;
                pre = arr[i];
            }
            if(cnt ==3){
                return arr[i];
            }
        }
        return arr[0];
        
   
    }
};