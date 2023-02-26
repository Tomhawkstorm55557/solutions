class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int>ans(n);
        map<int,vector<int>>m;
        //step 1 aab ek graph
        for(auto a:paths){
            m[a[0]].push_back(a[1]);
              m[a[1]].push_back(a[0]);
        }
        //int i = 1 kyuki indexiing 0 saa haa
        for(int i =1;i<=n;i++){
            //aab ek vixited banta haa
            vector<int>visited(5,0);
            for(auto t:m[i]){
                //agar pahela he planting ha flower toh
                visited[ans[t-1]]=1;
            }
            // jo plant bacha haa unha laga deta haa
            for(int j =1;j<=4;j++){
             if(visited[j]==0){   
                ans[i-1]=j;
                 
                break;
             }   
            }
        }
        return ans;
    }
};