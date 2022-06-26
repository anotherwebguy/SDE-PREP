/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool recur(TreeNode* A, int B, vector<int> &res){
    if(!A) return false;
    res.push_back(A->val);
    if(A->val==B) return true;
    if(recur(A->left,B,res) || recur(A->right,B,res)) return true;
    res.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    recur(A,B,res);
    return res;
}

//O(N)-both
