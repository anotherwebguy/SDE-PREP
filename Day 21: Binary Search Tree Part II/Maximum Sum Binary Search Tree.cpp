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
    vector<pair<int,TreeNode*>> v;
    
    int calcSum(TreeNode*root){
        if(!root) return 0;
        int l = calcSum(root->left);
        int r = calcSum(root->right);
        v.push_back({l+r+root->val,root});
        return l+r+root->val;
    }
    
    bool check(TreeNode* root,int high, int low){
        if(!root) return true;
        if(low<root->val && root->val<high){
            return check(root->left,root->val,low) && check(root->right,high,root->val);
        }
        return false;
    }
    
    int maxSumBST(TreeNode* root) {
        calcSum(root);
        sort(v.begin(),v.end(),greater<pair<int,TreeNode*>>());
        for(int i=0;i<v.size();i++){
            if(v[i].first<0)
                break;
           if(check(v[i].second,INT_MAX,INT_MIN))
               return v[i].first;
        }
        return 0;
    }
};
//O(N^2)-time
