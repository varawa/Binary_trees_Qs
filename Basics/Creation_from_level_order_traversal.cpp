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

node* build_from_level_order(node* root){
    queue<node*> q ;
    cout<<"Value of root : "<<endl ;
    int data ;
    cin>>data ;

    root = new node(data) ;
    q.push(root) ;

    while(!q.empty()){
        node* temp = q.front() ;
        q.pop() ;

        if(temp->data != -1){
            cout<<"Element in left of "<<temp->data<<endl ;
            int datal ;
            cin>>datal ;
            temp->left = new node(datal) ;
            q.push(temp->left) ;

            cout<<"Element in right of "<<temp->data<<endl ;
            int datar ;
            cin>>datar ;
            temp->right = new node(datar) ;
            q.push(temp->right) ;

        }
    }
    return root ;   
}

void level_order_traversal(node* root){
    queue<node*> q ;
    q.push(root) ;
    q.push(NULL) ;

    while(!q.empty()){
        node* temp = q.front() ;
        q.pop() ;
        if(temp != NULL && temp->data != -1){
            cout<<temp->data<<" " ;
        }
        if(temp == NULL){
            cout<<endl ;
            if(!q.empty()){
                q.push(NULL) ;
            }
        }
        else{
                if(temp -> left){
                    q.push(temp -> left) ;
                }
                if(temp ->right){
                    q.push(temp ->right) ;
                }
        }
    }
}

int main(){
    node* tree = NULL ; 
    tree = build_from_level_order(tree) ;
    level_order_traversal(tree) ;
    return 0 ;
}