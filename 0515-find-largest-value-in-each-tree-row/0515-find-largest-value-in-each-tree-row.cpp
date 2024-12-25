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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);
       
        while(!q.empty()){
            int sz = q.size();
            int mxval = INT_MIN;

            while(sz != 0){
                TreeNode* node = q.front();
                q.pop();
                mxval = max(mxval, node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                sz--;
            }
            ans.push_back(mxval);
        }
        return ans;
    }
};
