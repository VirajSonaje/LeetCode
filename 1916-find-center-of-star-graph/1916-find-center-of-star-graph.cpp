class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> adj;
        int n = edges.size();
        for(auto edge: edges){
            adj[edge[0]]++;
            adj[edge[1]]++;
        }
        for(auto node: adj) if(node.second == n) return node.first;

        return 0;
    }
};