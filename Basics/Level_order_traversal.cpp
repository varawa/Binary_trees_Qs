#include<iostream>
#include<queue>
using namespace std ;

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

void level_order_traversal(node* root){
    queue<node*> q ;
    q.push(root) ;
    q.push(NULL) ;
    
    while(!q.empty()){
        node* temp = q.front() ;
        if(temp != NULL){
            cout<<temp->data<<" ";
        }
        
        q.pop() ;

        if(temp == NULL){
            cout<<endl ;
            if(!q.empty()){
                q.push(NULL) ;
            }
        }
        
        else{
            
            if(temp->left){
                q.push(temp->left) ;
            }

            if(temp->right){
                q.push(temp->right) ;
            }
        }
    }
}

int main(){
    node* root = NULL ;

    root = build_tree(root) ;
    level_order_traversal(root) ;
    return 0 ;
}