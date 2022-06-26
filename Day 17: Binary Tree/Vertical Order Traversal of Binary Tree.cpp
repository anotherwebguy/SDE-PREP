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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int,map<int,multiset<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            m[temp.second.first][temp.second.second].insert(temp.first->val);
            if(temp.first->left!=NULL){
                q.push({temp.first->left,{temp.second.first-1,temp.second.second+1}});
            }
            if(temp.first->right!=NULL){
                q.push({temp.first->right,{temp.second.first+1,temp.second.second+1}});
            }
        }
        for(auto i:m){
            vector<int> t;
            for(auto j:i.second){
                for(auto k:j.second) t.push_back(k);
            }
            res.push_back(t);
        }
        return res;
    }
};

//O(N*logN*logN*logN)-time
//O(N)-space
