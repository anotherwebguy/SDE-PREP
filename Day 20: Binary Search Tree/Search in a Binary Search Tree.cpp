//Method 1 queue O(logN)-both
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
    TreeNode* searchBST(TreeNode* root, int val) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            if(temp->val==val) return temp;
            else if(temp->val>val) {
                if(temp->left) q.push(temp->left);
            } else {
                if(temp->right) q.push(temp->right);
            }
        }
        return NULL;
    }
};

//Method 2 recur O(logN)

TreeNode* searchBST(TreeNode* root, int val) {
  if(!root)return NULL;
  if(root->val==val)return root;
  else if(root->val>val)return searchBST(root->left,val);
  else
  return searchBST(root->right,val);
}

