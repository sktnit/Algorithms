#include <bits/stdc++.h>
using namespace std;

struct node{
    int key;
    node *left, *right;
    int lcount, rcount;
};


class BST {
private:
   node* root;
public:
    node* new_node(int key);
    void LR(int key);
    bool search1(int );
    bool search2(int );
    node* LR(node* );
    void RR(int key);
    node* RR(node*);
    void PRE_ORDER();
    void PRE_ORDER(node *root);
    void insert(int key);
    void insert(node **root, int key);
    BST() {
        root = NULL;
    }
};

node* BST :: RR(node* ptr)
{
    node* temp=ptr->left;
    node* y =temp->right;
    temp->right=ptr;
    ptr->lcount=x->rcount;
    ptr->left=y;
    temp->rcount=ptr->lcount+ptr->rcount+1;
    return temp;
}

node* BST :: LR(node* ptr)
{
    node* temp=ptr->right;
    node* y=temp->left;
    temp->left=ptr;
    ptr->right=y;
    ptr->rcount=temp->lcount;
    temp->lcount=ptr->lcount+ptr->rcount+1;
    return temp;
}
void BST::RR(int key)
{
    node* temp=NULL;
    node* parent=root;
    while (parent->key != key)
    {
        if(parent->key < key)
        {
            temp=parent;
            parent=parent->right;
        }
        else if(parent->key > key)
        {
            temp=parent;
            parent=parent->left;
        }
    }
        if(temp==NULL)
        {
            root=RR(parent);
        }
        else if(temp->left==parent)
        {
            temp->left=RR(parent);
        }
        else if(temp->right==parent)
            temp->right=RR(parent);
}

void BST::LR(int key)
{
    node* temp=NULL;
    node* parent=root;
    while (parent->key != key)
    {
        if(parent->key < key)
        {
            temp=parent;
            parent=parent->right;
        }
        else if(parent->key > key)
        {
            temp=parent;
            parent=parent->left;
        }
    }
        if(temp==NULL)
        {
            root=LR(parent);
        }
        else if(temp->left==parent)
        {
            temp->left=LR(parent);
        }
        else if(temp->right==parent)
            temp->right=LR(parent);
}

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

node* BST::new_node(int key){
    node* temp = new node;
    temp->key = key;
    temp->lcount=0;
    temp->rcount=0;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void BST::PRE_ORDER()
{
    PRE_ORDER(root);
}

void BST::PRE_ORDER(node *root)
{
    if(root==NULL)
    return ;
    cout<<"("<<root->key<<" " <<root->lcount<<" "<<root->rcount<<") ";
    PRE_ORDER(root->left);
    PRE_ORDER(root->right);
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
        (*root)->rcount++;
         insert(&((*root) -> right), key);
      }
      else if((*root) -> key > key){
          (*root)->lcount++;
         insert(&((*root) -> left), key);
      }
   }
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
            bst.PRE_ORDER();
        }
    }
    return 0;
}
