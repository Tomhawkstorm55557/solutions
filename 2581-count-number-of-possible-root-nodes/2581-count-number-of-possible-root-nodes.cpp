class Solution 
{
public:
    map<pair<int,int>,int> m;
    int f(int node, vector<int> adj[], int par, set<vector<int>> &g)
    {
        int cnt=0;
        if(m.find({node,par})!=m.end()) return m[{node,par}];
        for(auto it: adj[node])
        {
            if(it!=par)
            {
                vector<int> v={node,it};
                if(g.find(v)!=g.end()) cnt++;
                cnt+=f(it,adj,node,g);
            }
        }
        return m[{node,par}]=cnt;
    }
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) 
    {
        int n=edges.size()+1;
        vector<int> adj[n];
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        set<vector<int>> g;
        for(auto it: guesses) g.insert(it);
        int cnt=0;
        for(int x=0; x<n; x++)
        {
            int ans=f(x,adj,-1,g);
            if(ans>=k) cnt++;
        }
        return cnt;
    }
};