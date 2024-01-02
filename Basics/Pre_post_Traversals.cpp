#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data ;
        node* right ;
        node* left ;

        node(int d){
            this->data = d ;
            this->right = NULL ;
            this->left = NULL ;
        }
};

node* build_tree(node* root){
    cout<<"Enter the data for node : "<<endl ;
    int data ;
    cin>>data ;

    root = new node(data) ;

    if(data == -1){
        return NULL ;
    }

    cout<<"Enter data for inserting in left of "<<root->data<<": " <<endl ;
    root->left = build_tree(root->left) ;

    cout<<"Enter data for inserting in right of the tree "<<root->data<<": "<<endl ;
    root->right = build_tree(root->right) ;

    return root ;
}

void pre_order_traversal(node* root){
    cout<<root->data<<" " ;

    if(root -> left){
        pre_order_traversal(root->left) ;
    }

    if(root -> right){
        pre_order_traversal(root->right) ;
    }
}

void post_order_traversal(node* root){

    if(root -> left){
        post_order_traversal(root->left) ;
    }

    if(root -> right){
        post_order_traversal(root->right) ;
    }
    
    cout<<root->data<<" " ;
}

void in_order_traversal(node* root){

    if(root -> left){
        in_order_traversal(root->left) ;
    }

    cout<<root->data<<" " ;
    
    if(root -> right){
        in_order_traversal(root->right) ;
    }
}

int main(){
    node* tree ;
    tree = build_tree(tree) ;
    
    cout<<"Preorder traversal : "<<endl ;
    pre_order_traversal(tree) ;
    cout<<endl<<"Postorder traversal : "<<endl ;
    post_order_traversal(tree) ;
    cout<<endl<<"Inorder traversal : "<<endl ;
    in_order_traversal(tree) ;

    return 0 ;
}