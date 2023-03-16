class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            //making a graph
            adj[it[0]].push_back({it[1],it[2]});
        }
        // step -2 queue banoga
        // toh jo queue banoga usma step source aur cost hogaaa okk
        queue<pair<int,pair<int,int>>>q;
        //step -3 push kardoga
        q.push({0,{src,0}});
        // o-step,src,0-cost
        // update karna ka array banega
        vector<int>dist(n,1e6);
        dist[src]=0;
        //aab vahi ek ek ko nikala kar check karoo boringgggg
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            // teen variable assign 
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            // base condition
            if(stops>k){
                continue;
            }
            for(auto iter :adj[node] ){
                int adjNode = iter.first;
                int edw = iter.second;
                if(cost +edw<dist[adjNode]){
                    // update the distece
                    dist[adjNode]=cost+edw;
                 q.push({stops + 1, {adjNode, cost + edw}});
                    
                }
            }
        }
        /// base condition
        if(dist[dst]==1e6){
            return -1;
        }
        return dist[dst];
        
    }
};