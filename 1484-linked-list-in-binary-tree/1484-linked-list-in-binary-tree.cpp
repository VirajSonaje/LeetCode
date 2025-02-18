/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(root, head, head);
    }

    bool dfs(TreeNode* root, ListNode* head, ListNode* node){
        if(node == NULL) return true;
        if(root == NULL) return false;

        if(node->val == root-> val){
            node = node->next;
        }
        else if(head-> val == root->val){
            head = head->next;
        }
        else{
            node = head;
        }

        return dfs(root->left, head, node) || dfs(root->right, head, node);
    }
};