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
    int maxD;
public:
    int amountOfTime(TreeNode* root, int start) {
        maxD = 0;
        getDepth(root, start);
        return maxD;
    }

    int getDepth(TreeNode* root, int start){
        if(root == NULL) return 0;

        int left = getDepth(root->left, start);
        int right = getDepth(root->right, start);

        if(root->val == start){
            maxD = max(maxD, max(left, right));
            return -1;
        }
        else if(left <0 || right<0){
            maxD = max(maxD, abs(left)+abs(right));
            return min(left, right) -1;
        } 
        int dpth = max(left, right) + 1;
        maxD = max(maxD, dpth);
        return dpth;
    }
};