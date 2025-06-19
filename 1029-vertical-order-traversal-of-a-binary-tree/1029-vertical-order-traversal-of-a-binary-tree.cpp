/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int, int>, multiset<int>> mp;
        map<int, vector<int>> cols;
        dfs(root, mp, 0, 0);

        for(auto it: mp){
            int x = it.first.second;
            for(int val: it.second){
                cols[x].push_back(val);
            }
        }

        vector<vector<int>> ans;
        for(auto it: cols){
            ans.push_back(it.second);
        }

        return ans;
    }

    void dfs(TreeNode*root, map<pair<int, int>, multiset<int>> &mp, int i, int j){
        if(!root) return;

        mp[{i, j}].insert(root->val);
        dfs(root->left, mp, i+1, j-1);
        dfs(root->right, mp, i+1, j+1);      
    }
};