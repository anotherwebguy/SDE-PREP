//Method 1 - recur+binary search (Nlogn)-time O(N)-space
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
    TreeNode* convert(vector<int> &preorder,int s,int e){
        if(s>e) return NULL;
        TreeNode* root = new TreeNode(preorder[s]);
        int x = upper_bound(preorder.begin()+s+1,preorder.begin()+e+1,preorder[s])-preorder.begin();
        root->left = convert(preorder,s+1,x-1);
        root->right = convert(preorder,x,e);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = convert(preorder,0,preorder.size()-1);
        return root;
    }
};

//Method 2 recur + upper bound (N)-time O(1)-space
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
    TreeNode* convert(vector<int> &preorder,int s,int e){
        if(s>e) return NULL;
        TreeNode* root = new TreeNode(preorder[s]);
        int x = upper_bound(preorder.begin()+s+1,preorder.begin()+e+1,preorder[s])-preorder.begin();
        root->left = convert(preorder,s+1,x-1);
        root->right = convert(preorder,x,e);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = convert(preorder,0,preorder.size()-1);
        return root;
    }
};
