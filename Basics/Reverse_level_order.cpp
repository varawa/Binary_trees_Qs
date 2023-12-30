#include<iostream>
#include<stack>
#include<queue>
using namespace std;

//By using one stack and one queue .

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

void reverse_level_order_traversal(node* root){
    stack<node*> s ;
    queue<node*> q ;

    q.push(root) ;
    q.push(NULL) ;
    while(!q.empty()){
        node* temp = q.front() ;
        q.pop() ;
        s.push(temp) ;

        if(temp != NULL){
        
            if(temp->right){
                q.push(temp->right) ;
            }
            if(temp->left){
                q.push(temp->left) ;
            }
        }
        
    }

    while(!s.empty()){
        node* t = s.top() ;
        if(t == NULL){
            cout<<endl ;
        }
        else{
            cout<<t->data ;
        }
            s.pop() ;
    }
}

int main(){
    node* root = NULL ;

    root = build_tree(root) ;
    reverse_level_order_traversal(root) ;
    return 0 ;
}

