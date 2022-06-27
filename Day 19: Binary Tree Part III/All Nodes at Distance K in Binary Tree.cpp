/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> m;
        map<TreeNode*,int> vis;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            if(temp->left) {
                q.push(temp->left);
                m[temp->left]=temp;
            }
            if(temp->right){
                q.push(temp->right);
                m[temp->right]=temp;
            }   
        }
        int dis=0;
        while(!q.empty()) q.pop();
        vector<int> res;
        q.push(target);
        vis[target]=1;
        while(!q.empty()){
            int x = q.size();
            if(dis++==k) break;
            for(int i=0;i<x;i++){
                auto temp = q.front();
                q.pop();
                if(temp->left && !vis[temp->left]){
                    q.push(temp->left);
                    vis[temp->left]=1;
                }
                if(temp->right && !vis[temp->right]){
                    q.push(temp->right);
                    vis[temp->right]=1;
                }
                if(m[temp] && !vis[m[temp]]){
                    q.push(m[temp]);
                    vis[m[temp]]=1;
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};

//O(3*N)-both
