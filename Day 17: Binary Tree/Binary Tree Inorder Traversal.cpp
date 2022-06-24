// Method-1 Recursion
// O(n)-time & space since 2*T(n/2)+1

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
    void traverse(TreeNode* root,vector<int> &res){
        if(root!=NULL){
            traverse(root->left,res);
            res.push_back(root->val);
            traverse(root->right,res);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root,res);
        return res;
    }
};

// Method-2 Stacks
//O(n) time & space

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(curr!=NULL || !s.empty()){
            while(curr!=NULL){
                s.push(curr);
                curr=curr->left;
            }
            res.push_back(s.top()->val);
            curr=s.top();
            s.pop();
            curr=curr->right;
        }
        return res;
    }
};
