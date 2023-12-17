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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(root == NULL) return answer;
        queue<vector<TreeNode*>> trav;
        TreeNode* node = root;
        vector<int> temp;
        temp.push_back(node->val);
        answer.push_back(temp);
        vector<TreeNode*> t;
        t.push_back(node);
        trav.push(t);
        while(!trav.empty()){
            t.clear();
            temp.clear();
            vector<TreeNode*> x = trav.front();
            trav.pop();
            for(TreeNode* a: x){
                cout<<a->val<<" ";
                if(a->left != NULL){
                    t.push_back(a->left);
                    temp.push_back(a->left->val);
            }
                if(a->right != NULL){
                    t.push_back(a->right);
                    temp.push_back(a->right->val);
            }
        }
            if(t.empty())break;
            trav.push(t);
            answer.push_back(temp);    
        
    }
        return answer;
    }   
};