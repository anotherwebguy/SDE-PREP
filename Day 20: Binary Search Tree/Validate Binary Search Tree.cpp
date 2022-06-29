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
    bool validate(TreeNode* root, long long lower, long long upper){
        if(!root) return true;
        if(root->val<=lower || root->val>=upper) return false;
        return (root->val>lower && root->val<upper) && validate(root->left,lower,root->val) && validate(root->right,root->val,upper);
    }
    bool isValidBST(TreeNode* root) {
        return validate(root,LLONG_MIN,LLONG_MAX);
    }
};

//O(n)
