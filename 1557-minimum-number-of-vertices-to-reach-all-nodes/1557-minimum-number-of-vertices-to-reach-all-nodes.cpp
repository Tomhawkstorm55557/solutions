class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>res,vis(n);
        for(auto i:edges){
            vis[i[1]]++;
        }
        for(int i =0;i<n;i++){
            if(vis[i]==0){
                res.push_back(i);
            }
        }
        return res;
    }
};