//Method 1 - stacks
//O(N)- time and space
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
        vector<int> res;
        stack<TreeNode*> s;
        if(root==NULL) return {};
        s.push(root);
        while(!s.empty()){
            auto node = s.top();
            s.pop();
            res.push_back(node->val);
            if(node->right!=NULL) s.push(node->right);
            if(node->left!=NULL) s.push(node->left);
        }
        return res;
        
    }
};

//Method 2 - recursion
//O(N) - time and space
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
            res.push_back(root->val);
            traverse(root->left,res);
            traverse(root->right,res);
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root,res);
        return res;
        
    }
};
