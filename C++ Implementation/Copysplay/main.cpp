/*original code*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class BST {
 public:
    struct node{
struct node *left;
int l;               //left size
int k;              //no. of keys greater than data
long int data;
int r;              //right size
struct node *right;
};
typedef struct node node;
node *root1=NULL,*root2=NULL,*searched_key=NULL;
long int th=0;
int flag=0,count=0;
// this definition is used for inserting node
node *creat_node(node *root,node *temp)
{
if(root==NULL)
{root=temp;
}
else
if((root->data) > (temp->data))
{   temp->k=root->k+1;
    root->l=root->l+1;
    root->left=creat_node(root->left,temp);}
else if((root->data) == (temp->data))
{
    root->l=root->l+1;
    root->left=creat_node(root->left,temp);}
else
{   root->k=root->k+1;
    root->r=root->r+1;
    pre_order2(root->left);
    root->right=creat_node(root->right,temp);
}

    return root;
}
// this definition is used for left rotaion
node *LR(node *root)
{

      node *temp=root->right;
       root->right=temp->left;
       root->r=temp->l;
       temp->left=root;
       temp->l=root->l+root->r+1;
       root=temp;
       return root;
}

// this definition is used for right rotaion
node *RR(node *root)
{

       node *temp=root->left;
       root->l=temp->r;
       root->left=temp->right;
       temp->right=root;
       temp->r=root->l+root->r+1;
       root=temp;
       return root;
}
// this definition is used for splaying the BST
node *splay(node *root,int key)
{
    if (root==NULL || root->data == key)
        return root;
    if (root->data > key)
    {
        if ((root->left)==NULL) return root;
        if (root->left->data > key)
        {
            root->left->left = splay(root->left->left, key);
            root = RR(root);
        }
        else if (root->left->data < key)
        {
            root->left->right = splay(root->left->right, key);
            if (root->left->right)
                root->left = LR(root->left);
        }

        return (root->left == NULL)? root: RR(root);
    }
    else
    {
        if (root->right==NULL) return root;
        if (root->right->data > key)
        {
            root->right->left = splay(root->right->left, key);
            if (root->right->left)
                root->right = RR(root->right);
        }
        else if (root->right->data < key)
        {
            root->right->right = splay(root->right->right, key);
            root = LR(root);
        }
        return (root->right == NULL)? root: LR(root);
    }
}
// this definition is used for finding search key
node *search_tree(node *root,int x)
{
if(root==NULL)
return root;
else
if(x==root->data)
{  searched_key=root;
    return root;}
else if(x > root->data)
root->right=search_tree(root->right,x);
else
root->left=search_tree(root->left,x);

 return root;
}
// this definition is used for printing output
void pre_order1(node *root)
    {
        if(root)
        {
            cout<<"("<<root->data<<" "<<root->l<<" "<<root->r<<")"<<" ";
            pre_order1(root->left);
            pre_order1(root->right);
        }
    }
 /* this definition is used for increasing the no. of keys,when insert key goes right it means one key greater than all the ke present in left side so, you easily calculate no. of keys greater than that node.*/
void pre_order2(node *root)
    {
        if(root)
        {
            root->k=root->k+1;
            pre_order2(root->left);
            pre_order2(root->right);
        }
    }
  /* this definition is used when you are splitting the node,after splitting no. of key greater than that node decreases in root1. */
    void pre_order3(node *root,int count)
    {
        if(root)
        {
            root->k=root->k-count;
            pre_order3(root->left,count);
            pre_order3(root->right,count);
        }
    }
/* this definition is used when you are joining the nodes,after joining no. of key greater than that node increases in root1.*/
    void pre_order4(node *root,int count)
    {
        if(root)
        {
            root->k=root->k + count;
            pre_order4(root->left,count);
            pre_order4(root->right,count);
        }
    }


 void INSERT(int val)
{node *temp = new node;
temp->data=val;
 temp->k=0;
 temp->l=0;
 temp->r=0;
temp->left = NULL;
temp->right = NULL;
if(flag==0 || val<=th)
{root1=creat_node(root1,temp);
 root1=splay(root1,val);}
else
{
count++;
root2=creat_node(root2,temp);
root2=splay(root2,val);
}
}

void SEARCH(int val)
{if(flag==0 || val<=th)
{root1=search_tree(root1,val);
 if(searched_key != NULL)
{cout<<"YES "<<searched_key->k<<endl;
 root1=splay(root1,val);}
 else
     cout<<"NO"<<endl;
}
else
 {  root2=search_tree(root2,val);
   if(searched_key != NULL)
   {cout<<"YES "<<searched_key->k<<endl;
    root2=splay(root2,val);}
 else
     cout<<"NO"<<endl;
 }
}

void SPLIT(int val)
{if(flag==0 && root1!=NULL)
{root1=splay(root1,val);
root2=root1->right;
root1->right=NULL;
count=root1->k;
pre_order3(root1,count);
th=val;
flag=1;
}
}
void JOIN()
{if(flag)
{root1=splay(root1,th);
 pre_order4(root1,count);
root1->right=root2;
if(root2 != NULL)
 root1->r=root2->l + root2->r + 1;
count=0;
root2=NULL;
th=0;
flag=0;}
}

void PRE_ORDER()
  {   if(flag==0)
      pre_order1(root1);
  }

};


int main() {
    int T, N;
    string s;
    cin >> T;
    BST splay_bst;
    for(int t=0; t<T; t++){
        cin >> s;
        if(s == "INSERT"){
            cin >> N;
            splay_bst.INSERT(N);
        }
        else if(s == "SEARCH")
        {
            cin >> N;
           splay_bst.SEARCH(N);
        }
        else if(s == "SPLIT")
        {
            cin >> N;
           splay_bst.SPLIT(N);
        }
         else if(s == "JOIN")
      {
          splay_bst.JOIN();
       }

     else if(s == "PRE-ORDER")
                {
                   splay_bst.PRE_ORDER();
                     cout<<endl;
                    }

         // continue from here
    }
    return 0;
}


