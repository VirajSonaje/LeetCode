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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return getLeaves(root1) == getLeaves(root2); 
    }

    vector<int> getLeaves(TreeNode* root){
        if(root == NULL) return {};
        if(root->left == NULL && root->right == NULL) return {root->val};
        vector<int> l, r;
        l = getLeaves(root->left);
        r = getLeaves(root->right);
        l.insert(l.end(), r.begin(), r.end());
        return l;
    }
};