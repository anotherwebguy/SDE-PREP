//Method 1
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
    map<int,int> m;
    bool flag=false;
    void util(TreeNode* root,int k){
        if(root!=NULL && flag==false){
            util(root->left,k);
            if(m.count(k-root->val)){
                flag=true;
            }
            m[root->val]++;
            util(root->right,k);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        util(root,k);
        return flag;
    }
};

//Method 2
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
    vector<int> v;
    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int l = 0, r = v.size() -1;
        while(l<r){
            int sum = v[l] + v[r];
            if(sum == k)
                return true;
            else if(sum > k)
                r--;
            else l++;
        }
        return false;
    }
};
