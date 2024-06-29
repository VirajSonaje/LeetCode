class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        vector<vector<int>> adj(n);

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }

        for(int i=0; i<n; i++){
            vector<bool> visited(n, false);
            dfs(adj, i, visited, i, ans);
        }

        for(auto parentlist : ans) sort(parentlist.begin(), parentlist.end());

        return ans;
    }

    void dfs(vector<vector<int>> &adj, int node, 
    vector<bool> &visited, int parent, vector<vector<int>>& ans){
        visited[node] = true;
        for(int nextnode : adj[node]){
            if(!visited[nextnode]){
                ans[nextnode].push_back(parent);
                dfs(adj, nextnode, visited, parent, ans);
            }
        }
    }
};