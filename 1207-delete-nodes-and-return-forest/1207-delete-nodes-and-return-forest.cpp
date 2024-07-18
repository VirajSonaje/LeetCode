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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root == NULL) return {};
        vector<TreeNode*> ans;
        unordered_map<int, int> del;
        
        for(int i: to_delete) del[i] = 1;
        helper(root, del, ans);
        if(root != NULL) ans.push_back(root);
        return ans;

    }

    void helper(TreeNode* &root, unordered_map<int,int> del, vector<TreeNode*> &ans){
        if(root->left != NULL){
            helper(root->left, del, ans);
        }
        if(root->right != NULL){
            helper(root->right, del,ans);
        }

        if(del[root->val]){
            if(root->left != NULL)ans.push_back(root->left);            
            if(root->right != NULL)ans.push_back(root->right);
            root = NULL;
        }

    }
};