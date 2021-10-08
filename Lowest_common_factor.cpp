// Lowest Common Ancestor

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key; 
    Node *left; //node pointer left
    Node *right;
    Node (int k)
    {
        key=k;
        left=NULL;
        right=NULL;
    }
    
};

Node *lca(Node *root,int n1, int n2)
{
    if(root==NULL)
        return NULL;                                    // lca(10)
    if(root->key==n1 || root->key==n2)                 //  |--->lca(20)           
        return root;                                   //  |    |->lca(NULL)
    Node *lca1=lca(root->left,n1,n2);                  //  |    |->lca(NULL)
    Node *lca2=lca(root->right,n1,n2);                 //  |--->lca(30)
    if(lca1!=NULL && lca2!=NULL)                       //  |    |->lca(40)  
        return root;                                   //  |    |->lca(50)  
    if(lca1!=NULL)                                            
        return lca1;                                         
    else                                                            
        return lca2;                                                    
}

