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
    private: 
    int idx =0;
public:
    int kthSmallest(TreeNode* root, int k) {
        //post order traversal
        int r = -1, l = -1;
        if(root->left)l = kthSmallest(root->left, k);
        if(l != -1) return l;

        idx++;
        if(k == idx) return root->val;
        
        if(root->right)r = kthSmallest(root->right, k);
        if(r != -1) return r;
            
        
        return -1;
    }
};