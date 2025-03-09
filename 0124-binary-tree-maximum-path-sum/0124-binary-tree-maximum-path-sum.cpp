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
    int maxsum;
    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;
        findsum(root);

        return maxsum;
    }

    int findsum(TreeNode* node){
        if (!node) return 0;
        int leftMaxPath = max(findsum(node->left), 0);
        int rightMaxPath = max(findsum(node->right), 0);
        int maxIfNodeIsRoot = node->val + leftMaxPath + rightMaxPath;
        maxsum = max(maxsum, maxIfNodeIsRoot);
        return node->val + max(leftMaxPath, rightMaxPath);
    }
};