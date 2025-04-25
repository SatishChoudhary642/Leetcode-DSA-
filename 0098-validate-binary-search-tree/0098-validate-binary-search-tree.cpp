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
    bool vBST(TreeNode* root, long long l, long long r){
        if(root==NULL){
            return true;
        }
        if(root->val < r and root->val > l){
            return vBST(root->left, l, root->val) && vBST(root->right, root->val, r);
        }
        else{
            return false;
        } 
    }
    bool isValidBST(TreeNode* root) {
        return vBST(root, LLONG_MIN, LLONG_MAX);
    }
};