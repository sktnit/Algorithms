
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
}* root;

class BST{

    public:
    BST()
    {
        root=NULL;
    }
         int insert(int key);
         int ceil(int num);
         int height();

};
/* Create your class(es) here
   You may use more than one class */
int BST:: insert(int key)
{
    int level=0;
    node *ptr=new node;
    node *p;
    ptr->data=key;
    ptr->left=NULL;
    ptr->right=NULL;
    p=NULL;
    if(root==NULL)
    {
        root=ptr;
    }
    else
    {
        node *q;
        q=root;
        while(q)
        {
            level++;
            p=q;
            if(ptr->data > q->data)
            {
                q = q->right;
            }
            else
            {
                q = q->left;
            }
        }
            if(ptr->data < p->data)
                p->left=ptr;
            else
                p->right=ptr;
    }
   return level;
}
int BST:: height()
{
    int height=0;
    if(root==NULL)
        return height;
    queue<node *> q;
    q.push(root);
    while (1)
    {
        int nodeCount = q.size();
        if (nodeCount == 0)
           return (height-1);
        height++;
        while (nodeCount > 0)
        {
            node *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
    }
}
int BST:: ceil(int num)
{
    int ceil=1000;
    node *q;
    q=root;
    while(!(q==NULL))
    {
        if(q->data==num)
        {
            ceil=q->data;
            return ceil;
        }
        else if(q->data<num)
        {
            q=q->right;
        }
        else if(q->data>num)
        {
            ceil=q->data;
            q=q->left;
        }
        else break;
    }
    return ceil;
}



// ! DO NOT CHANGE WHEN SUBMITTING !
int main() {

    int N,val;
    string cmd;

    BST tree;   // BST is the class you have to create.
      // Contains atleast 3 public methods.
      // insert(val), ceil(val), height()

    cin >> N;
    for(int i=0;i<N;++i) {
   cin >> cmd;
   if(cmd == "insert") {

      cin >> val;

      cout << tree.insert(val) << "\n";
   } else if(cmd == "ceil") {
      cin >> val;

      cout << tree.ceil(val) << "\n";
   } else if(cmd == "height") {

      cout << tree.height() << "\n";
   }

   }
    return 0;
}
// ! DO NOT CHANGE UNTIL THIS LINE
