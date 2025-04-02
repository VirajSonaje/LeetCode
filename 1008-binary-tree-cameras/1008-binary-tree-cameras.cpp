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
    int minCameraCover(TreeNode* root) {
        int cams = 0;
        int ans = dfs(root,cams);

        if(ans == 0) cams++;
        return cams;
    }

    int dfs(TreeNode* root, int &cams){
        if(root == NULL) return 1;
        int left = dfs(root->left, cams);
        int right = dfs(root->right, cams);

        if(left == 0 || right == 0){
            cams++;
            return 2;
        }
        if(left== 2 || right == 2){
            return 1;
        }
        return 0;
    }
};