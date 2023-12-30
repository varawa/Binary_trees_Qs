#include<iostream>
#include<queue>

using namespace std ;

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* root){
        
        int height = 0 ;
        
        if(root == NULL){
            return 0 ;
        }
        queue<Node*> q ;
        q.push(root) ;
        q.push(NULL) ;
        
        while(!q.empty()){
            Node* temp = q.front() ;
            q.pop() ;
            if(temp == NULL){
                height++ ;
                if(!q.empty())
                    q.push(NULL) ;
                }
            
            else{
                if(temp->left)
                    q.push(temp->left) ;
    
                if(temp->right)
                    q.push(temp->right) ;
                }
        }
        return height ;
    }
};