class Solution {
public:
    
    bool vis[105];
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        unordered_map<string, int> videos;
        int n=friends.size();
        queue<pair<int, int>>q;
        q.push({id, 0});
        vis[id] = true;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            if(p.second == level){
                for(string x:watchedVideos[p.first]){
                    videos[x]++;
                }
                continue;
            }
            
            for(int x:friends[p.first]){
                if(!vis[x]){
                    vis[x] = true;
                    q.push({x, p.second+1});
                }
            }
        }
        
        vector<pair<int, string>> movies;
        for(auto i:videos) movies.push_back({i.second,i.first});
        sort(movies.begin(), movies.end());
        vector<string>ans;
        for(auto i:movies) ans.push_back(i.second);
        return ans;
    }
};