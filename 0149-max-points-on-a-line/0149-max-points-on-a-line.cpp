class Solution {
public:
    
    int maxPoints(vector<vector<int>>& points) {
        int mx=0;
        for(int i=0; i<points.size(); i++){
            unordered_map<float, int>mp;
            int x1= points[i][0];
            int y1= points[i][1];
            
            for(int j=0; j<points.size()&& j!=i; j++){
                 int x2= points[j][0];
                 int y2= points[j][1];
                 float slp;
                 if(x2-x1!=0){
                    slp= (float)(y2-y1)/(x2-x1);
                 }else{
                    slp=INT_MAX;
                 }
                 
                 mp[slp]++;
                 mx= max(mp[slp], mx);
            }
        }
        return mx+1;
    }
};