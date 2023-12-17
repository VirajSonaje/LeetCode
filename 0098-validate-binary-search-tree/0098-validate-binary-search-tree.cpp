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
    bool isValidBST(TreeNode* root, long a = 2147483649, long i = -2147483648-1) {
        int l=0;
        int r=0;
        
        
        // cout<<"Node:"<<root->val<<" "<<a<<" "<<i<<"\n";
        if(root == NULL) return true;
          
        if(root->left == NULL) l = 2;
        else{
            long e = (a > root->val)? root->val: a;
            long h = (i > root->val)? root->val: i;
            if(root->left->val > h && root->left->val < e){
              if(isValidBST(root->left,e, h)) l=1;
        else return false;  
            }
            else return false;
        }
        if(root->right == NULL) r = 2;
        else{
             long e = (a < root->val)? root->val: a;
             long h = (i < root->val)? root->val: i;
            if(root->right->val > h && root->right->val < e){
               if(isValidBST(root->right,e, h)) r=1;
        else return false; 
            }
            else return false;
            
        }
        
        // cout<<l<<" "<< r<<"\n";
        if(l>0 && r>0) return true;
        return false;
    }

};