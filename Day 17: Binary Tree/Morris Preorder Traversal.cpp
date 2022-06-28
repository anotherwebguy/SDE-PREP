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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left==NULL){
                preorder.push_back(curr->val);
                curr=curr->right;
            } else {
                TreeNode* temp = curr->left;
                while(temp->right && temp->right!=curr){
                    temp=temp->right;
                }
                if(temp->right==NULL){
                    temp->right=curr;
                    preorder.push_back(curr->val);
                    curr=curr->left;
                } else {
                    temp->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return preorder;
    }
};

//O(N)-time
//O(1)-space
