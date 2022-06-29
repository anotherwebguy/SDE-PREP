//Method 1 recurr O(N)-both
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
    TreeNode* convert(vector<int> &nums,int s, int e){
        if(s>e) return NULL;
        int m = (s+e)>>1;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = convert(nums,s,m-1);
        root->right = convert(nums,m+1,e);
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = convert(nums,0,nums.size()-1);
        return root;
    }
};
