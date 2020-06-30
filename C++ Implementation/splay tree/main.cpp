#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long threshold=0;
int doub=0;

struct node{
    long key;
    node *left,*right;
}*root1,*root2,*found;

class BST {
public:
    BST()
    {
        root1=NULL;
        root2=NULL;
        found=NULL;
    }
    node* new_node(long);
    void INSERT(long);
    node* INSERT(node*,node*);
    void SEARCH(long);
    node* SEARCH(node*,long);
    void SPLIT(long);
    void JOIN();
    int SIZE(node*);
    void PREORDER();
    void PREORDER(node*);
    node* SPLAY(node* ,long );
    node* LR(node* root);
    node* RR(node* root);
};

//Left Rotation
node* BST:: LR(node* root)
{
    node *temp=root->right;
    root->right=temp->left;
    temp->left=root;
    root=temp;
    return root;
}

// Right Rotation
node* BST:: RR(node* root)
{
    node *temp=root->left;
    root->left=temp->right;
    temp->right=root;
    root=temp;
    return root;
}
int BST::SIZE(node* node)
{
    if (node==NULL)
        return 0;
    else{
        int temp=0;
        temp=(SIZE(node->left) + SIZE(node->right) +1);
        return temp;
    }

}

node* BST::SPLAY(node* root,long key)
{
    if (root==NULL || root->key== key)
        return root;
    if (root->key > key)
    {

        if (root->left->key > key)
        {
            root->left->left=SPLAY(root->left->left, key);
            root=RR(root);
        }
        else if (root->left->key < key)
        {
            root->left->right = SPLAY(root->left->right, key);
            if (root->left->right)
                root->left = LR(root->left);
        }
        if(root->left!=NULL)
            return RR(root);
        else
            return root;
    }
    else
    {
        if (root->right->key > key)
        {
            root->right->left = SPLAY(root->right->left, key);
            if (root->right->left)
                root->right = RR(root->right);
        }
        else if (root->right->key < key)
        {
            root->right->right = SPLAY(root->right->right, key);
            root = LR(root);
        }
        if(root->right!=NULL)
            return LR(root);
        else
            return root;
    }
}

node* BST::new_node(long key){
    node* temp = new node;
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void BST::INSERT(long key)
{
    node* temp=new_node(key);
    if(doub==0 || key<=threshold)
    {
        root1=INSERT(root1,temp);
        root1=SPLAY(root1,key);
    }
    else
    {
    root2=INSERT(root2,temp);
    root2=SPLAY(root2,key);
    }
}

node* BST::INSERT(node *root,node *temp)
{
    if(root == NULL)
        root=temp;
    else
    {
        if(root->key < temp->key)
            root->right=INSERT(root->right,temp);
        else if(root->key > temp->key)
            root->left=INSERT(root->left,temp);
    }
    return root;
}

void BST::SEARCH(long key)
{
    if(doub==0 || key<=threshold)
    {
        root1=SEARCH(root1,key);
        if(found != NULL)
        {
            root1=SPLAY(root1,key);
            int count=SIZE(root1->right);
            cout<<"YES "<<count<<endl;
        }
       else
     cout<<"NO"<<endl;
    }
    else
    {
        root2=SEARCH(root2,key);
        if(found != NULL)
        {
            root2=SPLAY(root2,key);
            int count=SIZE(root2->right);
            cout<<"YES "<<count<<endl;
        }
        else
        cout<<"NO"<<endl;
    }
}

node* BST ::SEARCH(node *root,long x)
{
    if(root==NULL || root->key==x)
    {
        found=root;
        return root;
    }
    else if(x > root->key)
        root->right=SEARCH(root->right,x);
    else
        root->left=SEARCH(root->left,x);
    return root;
}

void BST::SPLIT(long key)
{
    if(doub==0 && root1!=NULL)
    { root1 = SPLAY(root1,key);
    root2 = root1->right;
    root1->right = NULL;
    threshold = key;
    doub=1;
    }
}

void BST::JOIN()
{
    if(doub==1)
    {root1 = SPLAY(root1,threshold);
    root1->right = root2;
    root2= NULL;
    doub=0;
    }
}

void BST::PREORDER()
{
    PREORDER(root1);
}

void BST::PREORDER(node *root)
{
    if(root==NULL)
        return ;
    cout<<"("<<root->key<<" " <<SIZE(root->left)<<" "<<SIZE(root->right)<<") ";
    PREORDER(root->left);
    PREORDER(root->right);
}

int main()
{
    int T;
    long N;
    string s;
    cin >> T;
    BST bst;
    for(int t=0; t<T; t++)
    {
        cin >> s;
        if(s == "INSERT")
        {
            cin>>N;
            bst.INSERT(N);
        }
        if(s=="SEARCH")
        {
            cin>>N;
            bst.SEARCH(N);
        }
        if(s=="SPLIT")
        {
            cin>>N;
            bst.SPLIT(N);
        }
        if(s=="JOIN")
        {
            bst.JOIN();
        }
        if(s=="PRE-ORDER")
        {
            bst.PREORDER();
        }
    }
    return 0;
}

