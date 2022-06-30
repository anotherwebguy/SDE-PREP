/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *root, int x){
    // Write your code here.
    int suc=-1;
    while(root!=NULL){
        if(x==root->data) {
            suc=root->data;
            break;
        } else if(x>root->data){
            root=root->right;
        } else {   
            suc = root->data;
            root=root->left;
        }
    }
    return suc;
}

//O(logn)-time
