class Solution {
public:
    int countSeniors(vector<string>& dt) {
     int n = dt.size();
        int ans =0;
        for(int i =0;i<n;i++){
            string si = dt[i].substr(11,2);
            int age = stoi(si);
            if(age>60){
                ans++;
            }
        }
        return ans;
    }
};