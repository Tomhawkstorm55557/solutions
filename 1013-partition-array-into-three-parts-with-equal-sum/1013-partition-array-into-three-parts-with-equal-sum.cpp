class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int total = 0;

        total = accumulate(arr.begin(),arr.end(),0);
        if(total %3 != 0 ) return false;
        int req = total/3;
             int sum = 0;
        int count =0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==req){
                count++;
                sum =0;
            }
        }
        return count>=3;
    }
};