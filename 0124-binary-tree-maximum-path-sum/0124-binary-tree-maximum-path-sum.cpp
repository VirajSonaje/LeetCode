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
        maxsum =root->val;
        findsum(root);

        return maxsum;
    }

    int findsum(TreeNode* root){
        if(root->left == NULL && root->right == NULL) return root->val;
        int r =INT_MIN,l =INT_MIN;
        if(root->left != NULL) l = findsum(root->left), maxsum = max(maxsum, l);
        if(root->right != NULL) r = findsum(root->right), maxsum = max(maxsum, r);
        if(r != INT_MIN && l != INT_MIN)maxsum = max(root->val+l+r, maxsum);
        if(r != INT_MIN) maxsum = max(maxsum, r+root->val);
        if(l != INT_MIN) maxsum = max(maxsum, l+root->val);  
        
        if(root->left == NULL) return max(root->val + r, root->val);
        if(root->right == NULL) return max(root->val + l, root->val);
        return max({root->val + r, root->val + l, root->val});


    }
};