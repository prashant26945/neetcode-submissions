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
    bool exists(TreeNode* root, TreeNode* target){
        if(root == NULL) return false;
        if(root == target) return true;
        return exists(root->left, target) || exists(root->right, target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) return root;
        else if(exists(root->left, p) == true && exists(root->right, q) == true) return root;
        //We can also write this by this way
        //else if(exists(root->left, p) && exists(root->right, q)) return root;
        else if(exists(root->right, p) && exists(root->left, q)) return root;
        else if(exists(root->left, p) && exists(root->left, q)) return lowestCommonAncestor(root->left, p, q);
        else return lowestCommonAncestor(root->right, p, q);
    }
};
