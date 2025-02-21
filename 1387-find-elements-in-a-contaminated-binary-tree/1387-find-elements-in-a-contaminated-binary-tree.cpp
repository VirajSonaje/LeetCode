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
class FindElements {
    unordered_map<int, bool> vals;
public:
    FindElements(TreeNode* root) {
        dfs(root, 0);
    }
    
    void dfs(TreeNode* node, int nodeVal){
        vals[nodeVal] = true;
        if(node->left) dfs(node->left, 2*nodeVal+1);
        if(node->right) dfs(node->right, 2*nodeVal+2);
    }

    bool find(int target) {
        return vals[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */