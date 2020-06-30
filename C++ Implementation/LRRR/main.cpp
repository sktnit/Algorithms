#include <bits/stdc++.h>
using namespace std;

struct node{
    int key;
    node *left, *right;
    int numofleft, numofright;
};

class BST {
private:
   node* root;
public:
    node* new_node(int key);
    bool search1(int );
    bool search2(int );
    node* search(node **temp, node *parent, int key);
    void LR(int key);
    void RR(int key);
    void PRE_ORDER();
    void PRE_ORDER(node *root);
    void insert(int key);
    void insert(node **root, int key);
    BST() {
        root = NULL;
    }
};
bool BST::search1(int key)
{
    int found=false;
    node* parent=root;
    while (parent->key != key)
    {
        if(parent->key < key)
        {
            parent=parent->right;
        }
        else if(parent->key > key)
        {
            parent=parent->left;
        }
    }
    if (parent->right)
        found=true;
    return found;
}

bool BST::search2(int key)
{
    int found=false;
    node* parent=root;
    while (parent->key != key)
    {
        if(parent->key < key)
        {
            parent=parent->right;
        }
        else if(parent->key > key)
        {
            parent=parent->left;
        }
    }
    if (parent->left)
        found=true;
    return found;
}

void BST :: LR(int key)
{
    node* temp=NULL;
    node* temp1=NULL;
    node* parent=NULL;
    parent=search(&root,parent,key);
    if(parent==NULL && root->right)
    {
        temp = root->right;
        root->right = temp->left;
        root->numofright=temp->numofleft;
        temp->left = root;
        temp->numofleft=temp->numofleft+root->numofright+1;
        root= temp;
    }

    else if((parent->key)< key &&(parent->right)->right )
    {
        temp=parent->right;
        temp1=temp->right;
        temp->right=temp1->left;
        temp->numofright=temp1->numofleft;
        temp1->left=temp;
        temp1->numofleft=temp->numofleft+temp->numofright+1;
        temp=temp1;
        parent->right=temp;
    }
    else if((parent->key)> key &&(parent->left)->right )
    {
        temp=parent->left;
        temp1=temp->right;
        temp->right=temp1->left;
        temp->numofright=temp1->numofleft;
        temp1->left=temp;
        temp1->numofleft=temp->numofleft+temp->numofright+1;
        temp=temp1;
        parent->left=temp;
    }
}

void BST::RR(int key)
{
    node* parent=NULL;
    node* temp=NULL;
    node* temp1=NULL;
    parent=search(&root,parent,key);
    if(parent==NULL && root-> left)
    {
        temp=root->left;
        root->left=temp->right;
        root->numofleft=temp->numofright;
        temp->right=root;
        temp->numofright=root->numofleft + root->numofright + 1;
        root=temp;
    }
    else if((parent->key)< key && (parent->right)->left)
    {
        temp=parent->right;
        temp1=temp->left;
        temp->left=temp1->right;
        temp->numofleft=temp1->numofright;
        temp1->right=temp;
        temp1->numofright=temp->numofleft+temp->numofright+1;
        temp=temp1;
        parent->right=temp;
    }
    else if((parent->key)> key && (parent->left)->left)
    {
        temp=parent->left;
        temp1=temp->left;
        temp->left=temp1->right;
        temp->numofleft=temp1->numofright;
        temp1->right=temp;
        temp1->numofright=temp->numofleft+temp->numofright+1;
        temp=temp1;
        parent->left=temp;

    }
}

node* BST::new_node(int key){
    node* temp = new node;
    temp->key = key;
    temp->numofleft=0;
    temp->numofright=0;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
node* BST:: search(node **temp,node *parent, int key)
{
   if(key==((*temp)->key))
        return(parent);
   if(key<((*temp)->key))
   {
       parent=search(&((*temp)->left),(*temp),key);
    }
    else
    {
        parent=search(&((*temp)->right),(*temp),key);
    }
    return parent;

}

void BST::insert(int key){
   insert(&root, key);
}

void BST::insert(node **root, int key){
   if(*root == NULL){
      *root = new_node(key);
   }
   else{
      if((*root) -> key < key){
          (*root)->numofright++;
         insert(&((*root) -> right), key);
      }
      else if((*root) -> key > key){
          (*root)->numofleft++;
         insert(&((*root) -> left), key);
      }
   }
}
void BST::PRE_ORDER()
{
    PRE_ORDER(root);
}

void BST::PRE_ORDER(node *root)
{
    if(root==NULL)
        return ;
    cout<<"("<<root->key<<" " <<root->numofleft<<" "<<root->numofright<<") ";
    PRE_ORDER(root->left);
    PRE_ORDER(root->right);
}

int main() {
    int T, N;
    string s;
    cin >> T;
    BST bst;
    for(int t=0; t<T; t++){
        cin >> s;
        if(s == "INSERT"){
            cin >> N;
            bst.insert(N);
        }
         // continue from here
        if(s=="LR")
        {
            cin >> N;
            if(bst.search1(N))
            bst.LR(N);
        }
        if(s=="RR")
        {
            cin >> N;
            if(bst.search2(N))
            bst.RR(N);
        }
        if(s=="PRE-ORDER")
        {
            bst.PRE_ORDER();cout<<endl;
        }
    }
    return 0;
}
