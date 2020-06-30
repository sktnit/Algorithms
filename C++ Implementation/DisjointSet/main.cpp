#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int counts;
struct tree
{
    int r,d;
    tree *p;
};
vector<tree*> arr;
void makeset(int n)
{
    for(int i=1;i<=n;i++)
    {
        tree *t=(tree*)malloc(sizeof(tree));
        t->p=t;
        t->r=0;
        t->d=i;
        arr[i]=t;
        free(t);
    }
}
tree *find(tree *a)
{
    if(a!=a->p)
        a->p=find(a->p);
    return a->p;
}

void unionrank(tree *a, tree *b)
{
    a=find(a);
    b=find(b);
    if(a!=b)
    {
        if(a->r>b->r)
            a->p=b;
        else
            a->p=b;
        if(a->r==b->r)
            b->r++;
    }
}
int main()
{
    int n,q;
    cin>>n>>q;
    counts=n;
    makeset(n);
    string op;
    for(int i=1;i<=q;i++)
    {
        cin>>op;
        if(op=="UNION")
        {
            int a,b;
            cin>>a>>b;
            unionrank(arr[a],arr[b]);
            counts--;
        }
        if(op=="FIND")
        {
            int a;
            tree *t;
            cin>>a;
            t=find(arr[a]);
            cout<<t->d<<endl;
        }
        if(op=="CC")
        {
          cout<<counts<<endl;
        }
    }
    return 0;
}
