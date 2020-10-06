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

//for left subtree root is the check for max value
//for right subtree root is the check for min value
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        return isValid(root, LONG_MIN, LONG_MAX); 
    }
    
    bool isValid(TreeNode* root, long mn, long mx){
        
        if(!root) return true;
        
        if(root->val <= mn || root->val >= mx) return false;
        
        return isValid(root->left, mn, root->val) && isValid(root->right, root->val, mx);
    }
};