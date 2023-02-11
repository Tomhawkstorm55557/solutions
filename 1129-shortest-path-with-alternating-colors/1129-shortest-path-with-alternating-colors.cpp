class Solution {
    public:
   
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges){

        vector<int> dis(n , -1);
        //making ajacent list in a way to store 
        vector<pair<int, int>> adj[n + 1];
        // storing the all edges with color tag 1
        for (auto vec : redEdges){
            adj[vec[0]].push_back({vec[1], 1});
        }
        // storing all the edges with color 2
        for (auto vec : blueEdges){
            adj[vec[0]].push_back({vec[1], 2});
        }
        // building queue
        queue<vector<int>> q;
        // building queue that store three value edge dis and color tag
        q.push({0, 0, -1});
        // running until the queue 
        while (q.size() > 0){
            auto currVec = q.front();
            q.pop();
            int currv = currVec[0], edgeColor = currVec[2];
            // agar uksa distance vector ma default value haa toh usaa update kardoo
            if (dis[currv] == -1){
                dis[currv] = currVec[1];
            }
            for (auto &childPair : adj[currv]){
                int childV = childPair.first, edgeColorOfChild = childPair.second;
                // yeh dekhenga isma kya yeh visited haa ya nhi ya iska rdge color same haa ya nhi 
                if (childV != -1 && (edgeColor == -1 || edgeColor != edgeColorOfChild)){
                    q.push({childV, currVec[1] + 1, edgeColorOfChild});
                    childPair.first = -1;
                }
            }
        }
        return dis;
    }
};