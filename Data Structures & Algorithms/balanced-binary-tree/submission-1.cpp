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
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int l = levels(root->left);
        int r = levels(root->right);
        if(abs(l - r) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
