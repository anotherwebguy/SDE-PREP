//Method - 1 recursion
//O(N) - time & space
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
            traverse(root->right,res);
            res.push_back(root->val);
        }
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root,res);
        return res;
    }
};

//Method 2 - one stack
//O(N) - time & space
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
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(curr!=NULL || !s.empty()){
            if(curr!=NULL){
                s.push(curr);
                curr=curr->left;
            } else{
                TreeNode* temp = s.top()->right;
                if(temp==NULL){
                    temp = s.top();
                    s.pop();
                    res.push_back(temp->val);
                    while(!s.empty() && temp==s.top()->right){
                        temp = s.top();
                        s.pop();
                        res.push_back(temp->val);
                    }
                } else {
                    curr=temp;
                }
            }
        }
        return res;
    }
};

//Method 3 - two stacks
//O(N) - time & O(2N)-space
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
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        if(root==NULL) return {};
        s1.push(root);
        while(!s1.empty()){
            auto temp = s1.top();
            s2.push(temp);
            s1.pop();
            if(temp->left!=NULL) s1.push(temp->left);
            if(temp->right!=NULL) s1.push(temp->right);
            
        }
        while(!s2.empty()){
            res.push_back(s2.top()->val);
            s2.pop();
        }
        return res;
    }
};
