class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size();
        int m = edges2.size();
        vector<vector<int>> adj1(n+1);
        vector<vector<int>> adj2(m+1);

        for(auto edge: edges1) {adj1[edge[0]].push_back(edge[1]); adj1[edge[1]].push_back(edge[0]);}
        for(auto edge: edges2) {adj2[edge[0]].push_back(edge[1]); adj2[edge[1]].push_back(edge[0]);}
    
        int diam1 = findDiam(adj1);
        int diam2 = findDiam(adj2);

        int finalDiam = 1;
        finalDiam+= (diam1+1)/2;
        finalDiam+= (diam2+1)/2;
        return max(finalDiam, max(diam1, diam2));

    }

    int findDiam(vector<vector<int>> &adj){
        vector<bool> vis(adj.size(),false);
        vector<int> dist(adj.size(),0);
        dfs(0, vis, adj, dist,0);
        int corner;
        int maxDist = -1;
        for(int i=0; i<dist.size(); i++) 
        if(maxDist < dist[i]) corner = i, maxDist = dist[i];
        dfs(corner, vis, adj, dist, 0);
        maxDist = -1;
        for(int i=0; i<dist.size(); i++) 
        if(maxDist < dist[i]) maxDist = dist[i];
        return maxDist;
    }

    void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &dist, int step){
        vis[node] = true;
        dist[node] = step;
        for(int next: adj[node]){
            if(!vis[next]){
                dfs(next, vis, adj, dist, step+1);
            }
        }
        vis[node] = false;
    }
};