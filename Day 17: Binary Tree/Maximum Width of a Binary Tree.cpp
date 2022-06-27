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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root ) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int ans = 0;
        while(!q.empty()){
            int l = q.size();
            int minim = q.front().second;
            int minl,maxr;
            
            for(int i=0;i<l;i++){
                pair<TreeNode*,int> temp = q.front();
                q.pop();
                long long ci = temp.second - minim;
                if(i == 0) minl = ci;
                if(i == l-1) maxr = ci;
                if(temp.first->left){
                    q.push({temp.first->left,2*ci});
                }
                if(temp.first->right){
                    q.push({temp.first->right,2*ci + 1});
                }
            }

            ans = max(ans,maxr-minl + 1);
        }
        return ans;
    }
};

//O(N)-both
