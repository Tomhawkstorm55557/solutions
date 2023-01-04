class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        //Preparing adj List
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i=0; i<times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int d = times[i][2];
            adj[u].push_back({v,d});
        }
        
        //Dijkstra's Algo
        priority_queue< pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>> > pq;
        
        vector<int> distance(n+1, INT_MAX);
        distance[0]=0;
        
        pq.push({0,k});
        distance[k] = 0;
        
        while(!pq.empty())  {
            
            auto it = pq.top();
            pq.pop();
            int dist = it.first;
            int node = it.second;
            
            for(auto it : adj[node])    {
                int adjNode = it.first;
                int wt = it.second;
                
                int curr = wt + dist;
                
                if(curr<distance[adjNode])  {
                    distance[adjNode] = curr;
                    pq.push({curr,adjNode});
                }
            }
        }
        
        int mx = -1;
        for(int i=0; i<n+1; i++)  {
            // cout<<i<<" = "<<distance[i]<<"\n";
            if(distance[i]==INT_MAX)    {
                return -1;
            }
            mx = max(distance[i],mx);
        }
        
        return mx;
    }
};