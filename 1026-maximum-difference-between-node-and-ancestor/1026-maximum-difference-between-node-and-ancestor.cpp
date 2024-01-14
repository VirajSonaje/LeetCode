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
    int maxD = 0;
public:
    int maxAncestorDiff(TreeNode* root) {
        getDiff(root);
        return maxD;
    }
    
    vector<int> getDiff(TreeNode* root){
        if(root == NULL) return {};

        vector<int> left = getDiff(root->left);
        vector<int> right = getDiff(root->right);
        vector<int> minmax = {root->val, root->val};
        if(left.size() != 0){
            maxD = max(maxD, max(abs(left[0]-root->val), abs(left[1]-root->val)));
            minmax = {min(minmax[0], left[0]), max(minmax[1], left[1])};
        }
        if(right.size() != 0){
            maxD = max(maxD, max(abs(right[0]-root->val), abs(right[1]-root->val)));
            minmax = {min(minmax[0], right[0]), max(minmax[1], right[1])};
        }

        return minmax;
    }
};