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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p && q) return false;
        if(p && !q) return false;
        if(p->left == NULL && p->right == NULL && q->left == NULL && q->right == NULL) return (p-> val == q->val);
        bool a = false;
        bool b = false;
        a= isSameTree(p->left, q->left);
        b = isSameTree(p->right, q->right);
            
        
        if(p-> val == q->val && a && b) return true;
        return false;
    }
};