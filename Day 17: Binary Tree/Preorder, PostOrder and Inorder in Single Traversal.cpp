//Method 1 - stack
//O(N)- time & space
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
#include<bits/stdc++.h>


vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    stack<pair<BinaryTreeNode<int> *, int>> s;
    vector<vector<int>> res;
    vector<int> pre,post,in;
    if (!root)
            return {{}, {}, {}};
    s.push({root,1});
    while(!s.empty()){
        auto temp = s.top();
        s.pop();
        if(temp.second==1){
            pre.push_back(temp.first->data);
            s.push({temp.first,2});
            if(temp.first->left!=NULL) s.push({temp.first->left,1});
        } else if(temp.second==2){
            in.push_back(temp.first->data);
            s.push({temp.first,3});
            if(temp.first->right!=NULL) s.push({temp.first->right,1});
        } else {
            post.push_back(temp.first->data);
        }
    }
    res.push_back(in);
    res.push_back(pre);
    res.push_back(post);
    return res;
    
}

//Method 2 recursion
//O(N)-time & space
void traversal(BinaryTreeNode<int> *root, vector<int> &pre, vector<int> &in, vector<int> &post) {
    if(!root) return;
    
    pre.push_back(root -> data);
    
    traversal(root -> left, pre, in, post);
    in.push_back(root -> data);
    traversal(root -> right, pre, in, post);
    
    post.push_back(root -> data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<int> pre, in, post;
    
    traversal(root, pre, in, post);
    return {in, pre, post};
}
