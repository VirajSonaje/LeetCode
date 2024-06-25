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
    TreeNode* bstToGst(TreeNode* root) {
        createGst(root, 0);
        return root;
    }

    int createGst(TreeNode* root, int trickle){
        int returnVal = 0;
        if(root->right != NULL)trickle = createGst(root->right, trickle);

        root->val +=  trickle;
        trickle = root->val;

        if(root->left != NULL)trickle = createGst(root->left, trickle);
        

        return trickle;
    }
};