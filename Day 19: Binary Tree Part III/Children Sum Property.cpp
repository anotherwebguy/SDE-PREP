/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(!root) return;
    int childsum=0;
    if(root->left) childsum+=root->left->data;
    if(root->right) childsum+=root->right->data;
    if(childsum<root->data){
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    } 
    changeTree(root->left);
    changeTree(root->right);
    int tot=0;
    if(root->left) tot+=root->left->data;
    if(root->right) tot+=root->right->data;
    if(root->left || root->right) root->data = tot;
}  

//O(N)-both
