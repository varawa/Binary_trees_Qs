#include<iostream>

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

node* build_tree(node* &root){
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

int main(){
    node* root = NULL ;

    root = build_tree(root) ;
    cout<<root->data ;

    return 0 ;
}