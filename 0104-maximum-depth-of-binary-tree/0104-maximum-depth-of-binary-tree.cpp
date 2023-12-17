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
    int maxD =0;
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0; 
        maxdd(root, 1);
        return maxD;
    }
    
    void maxdd(TreeNode* node, int depth){
        if(depth > maxD) maxD = depth;
        if(node!=NULL){
            if(node->right !=NULL) maxdd(node->right, depth+1);
            if(node->left !=NULL) maxdd(node->left, depth+1);
        }
        
    }

};