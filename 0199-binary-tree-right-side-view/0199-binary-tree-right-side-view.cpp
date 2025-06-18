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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> ans;
        queue<TreeNode*> level;
        level.push(root);
        levelOrder(ans, level);

        return ans;
    }

    void levelOrder(vector<int> &lvlOrder, queue<TreeNode*> &level){ 
        if(level.empty()) return;
        int n = level.size();
        for(int i=0; i<n; i++){
            TreeNode* node = level.front();
            level.pop();
            if(i == n-1) lvlOrder.push_back(node->val);
            if(node->left != NULL) level.push(node->left);
            if(node->right != NULL) level.push(node->right);
            
        }

        levelOrder(lvlOrder, level);
    }
};