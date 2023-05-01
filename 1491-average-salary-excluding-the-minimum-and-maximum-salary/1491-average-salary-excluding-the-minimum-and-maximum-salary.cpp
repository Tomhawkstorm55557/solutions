class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        int mi=1e9,mx =0;
        double amt =0;
        for(int i =0;i<n;i++){
            mi = min(mi,salary[i]);
            mx = max(mx,salary[i]);
            amt+=salary[i];
        }
        double avg = amt-mi-mx;
        

        int t = n-2;
         
        double ans = avg/t;
        return ans;
    }
};