#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;

bool found= false;
struct NODE
{
    signed int key;
    int height;
    int lcnt;
    int rcnt;
    struct NODE *left;
    struct NODE *right;
}*root;

class AVL{
    public:
        AVL()
        {
           root=NULL;
        }
        int BF(NODE*);
        int HEIGHT(NODE*);
        NODE *LL(NODE*);
        NODE *LR(NODE*);
        NODE *RR(NODE*);
        NODE *RL(NODE*);
        NODE *BALANCING(NODE*);
        NODE *INSERT(NODE *,signed int );
        NODE *NXTMIN(NODE *);
        NODE *DELETE(NODE *,signed int );
        int KMIN(int k);
};

int AVL::HEIGHT(NODE *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int AVL::BF(NODE *N)
{
    if (N == NULL)
        return 0;
    return (HEIGHT(N->left)-HEIGHT(N->right));
}
//Function to Left_Left Rotation
NODE* AVL :: LL(NODE *ptr)
{
    NODE *tem;
    tem = ptr->left;
    ptr->left = tem->right;
    ptr->lcnt = tem->rcnt;
    tem->right = ptr;
    tem->height = max(HEIGHT(tem->left), HEIGHT(tem->right))+1;
    ptr->height=max(HEIGHT(ptr->left), HEIGHT(ptr->right))+1;
    tem->rcnt = ptr->lcnt+ptr->rcnt+1;
    return tem;
}

//Function to Left_Right Rotation
NODE* AVL :: LR(NODE *ptr)
{
    NODE *tem;
    tem = ptr->left;
    ptr->left = RR(tem);
    return LL(ptr);
}

//Function to Right_Right Rotation
NODE* AVL :: RR(NODE *ptr)
{
    NODE *tem;
    tem = ptr->right;
    ptr->right = tem->left;
    ptr->rcnt = tem->lcnt;
    tem->left = ptr;
    ptr->height=max(HEIGHT(ptr->left), HEIGHT(ptr->right))+1;
    tem->height = max(HEIGHT(tem->left), HEIGHT(tem->right))+1;
    tem->lcnt = ptr->lcnt+ptr->rcnt+1;
    return tem;
}

//Function to Right_Left Rotation
NODE* AVL :: RL(NODE *ptr)
{
    NODE *tem;
    tem = ptr->right;
    ptr->right = LL(tem);
    return  RR(ptr);
}

//Function to Balance the tree
NODE *AVL::BALANCING(NODE *tem)
{

    int bf = BF(tem);
    if (bf > 1)
    {
        if (BF(tem->left) > 0)
            tem = LL(tem);
        else
            tem = LR(tem);
    }
    else if (bf < -1)
    {
        if (BF(tem->right) > 0)
            tem = RL(tem);
        else
            tem = RR(tem);
    }
    return tem;
}

//Function to insert the node in AVL tree
NODE *AVL:: INSERT(NODE *root,signed int val)
{
    if (root == NULL)
    {
        root = new NODE;
        root->key = val;
        root->lcnt = 0;
        root->rcnt = 0;
        root->left = NULL;
        root->right = NULL;
        root->height=0;
        return root;
    }
    else if (val < root->key)
    {
        root->lcnt++;
        root->left = INSERT(root->left, val);
        root = BALANCING(root);
    }
    else if (val > root->key)
    {
        root->rcnt++;
        root->right = INSERT(root->right, val);
        root = BALANCING(root);
    }
    root->height = 1 + max(HEIGHT(root->left),HEIGHT(root->right));
    return root;
}

//Function to get minimum inorder successor of deleted element
NODE *AVL::NXTMIN(NODE* ptr)
{
    NODE *temp = ptr;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

//Function to Delete the node in AVL tree
NODE *AVL :: DELETE(NODE *root,signed int val)
{
    if (root == NULL)
        return root;

    if ( val < root->key )
    {
        root->left = DELETE(root->left,val);
        if(found==true)
            root->lcnt--;
    }
    else if( val > root->key )
    {
        root->right = DELETE(root->right,val);
        if(found==true)
            root->rcnt--;
    }

    else
    {
        found=true;
        if( (root->left == NULL) || (root->right == NULL) )
        {
            NODE *temp = root->left?root->left:root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
                free(temp);
                temp=NULL;
            }
        }
        else
        {
            NODE *temp = NXTMIN(root->right);
            root->key = temp->key;
            root->right = DELETE(root->right, temp->key);
        }
    }
    if (root == NULL)
      return root;
    root->height = 1 + max(HEIGHT(root->left),HEIGHT(root->right));
    int balance = BF(root);
    if (balance > 1 && BF(root->left) >= 0)
        return LL(root);
    if (balance > 1 && BF(root->left) < 0)
        return LR(root);
    if (balance < -1 && BF(root->right) <= 0)
        return RR(root);
    if (balance < -1 && BF(root->right) > 0)
        return RL(root);
    return root;
}

//Find the kth minimum in the AVL tree
int AVL :: KMIN(int k)
{
    int val=-1;
    if(k>(root->lcnt + root->rcnt)+1)
    {
        return 0;
    }
    if(root)
    {
        NODE *ptr= root;
        while(ptr)
        {
            if( (ptr->lcnt + 1) == k )
            {
                val = ptr->key;
                break;
            }
            else if( k > ptr->lcnt )
            {
                k = k - (ptr->lcnt + 1);
                ptr = ptr->right;
            }
            else
                ptr = ptr->left;
        }
    }
    return val;
}

//Main Function that takes a no. of commands
int main()
{
    int N;
    signed int val,a[MAX];
    char cmd;
    AVL tree;
    cin >> N;
    for(int i=0;i<N;++i)
    {
        cin >> cmd;
        if(cmd == 'i')
        {
            cin >> val;
            root=tree.INSERT(root,val);
        }
        else if(cmd == 'd')
        {
            cin >> val;
            root=tree.DELETE(root,val);
        }
        else if(cmd == 'm')
        {
            cin >> val;
            cout<<tree.KMIN(val)<<"\n";
        }
   }
   return 0;
}
