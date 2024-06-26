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
    void inOrder(TreeNode* root, vector<int> &trav){
        if(root == NULL) return;

        inOrder(root->left, trav);
        trav.push_back(root-> val);
        inOrder(root->right, trav);
    }

    TreeNode* createBBST(int low, int high, vector<int> &inorder){
        if(low > high) return NULL;
        
        int mid = low + (high - low)/2;
        TreeNode* node = new TreeNode(inorder[mid]);
        node->left = createBBST(low, mid-1, inorder);
        node->right = createBBST(mid+1, high, inorder);

        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL) return root;
        vector<int> inorder;
        inOrder(root, inorder);
        return createBBST(0, inorder.size()-1, inorder);
    }
};