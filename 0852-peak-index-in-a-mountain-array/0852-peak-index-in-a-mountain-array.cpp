class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n =arr.size();
        if(n<3){
            return 0;
        }
      //
        int i =0;
        while(arr[i]<arr[i+1]){
            i++;
        }
        return i;
    }
};