#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;

class node
{
    public:
    int dest;
    int cost;
    node *next=NULL;
};
int main()
{
    int N,M;
    cin>>N>>M;
    int BC[N];
    node *adjlist[N];
    for (int i=0;i<N;i++)
    {
        BC[i]=0;
        adjlist[i]=NULL;
    }
    //Create adjacency list
    for (int i=0;i<M;i++)
    {
        int start,dest,wt;
        cin>>start>>dest>>wt;
        node *temp1=new node;
        node *temp2=new node;
        temp1->dest=dest;
        temp1->cost=wt;
        temp1->next=NULL;
        temp2->dest=start;
        temp2->cost=wt;
        temp2->next=NULL;
        node *ptr1,*ptr2;
        ptr1=adjlist[start];
        ptr2=adjlist[dest];
        while(ptr1!=NULL && ptr1->next!=NULL)
           {
               ptr1=ptr1->next;
           }
        if(ptr1==NULL)
        {
            ptr1=temp1;
            adjlist[start]=ptr1;
        }
        else
            ptr1->next=temp1;
        while(ptr2!=NULL && ptr2->next!=NULL)
            ptr2=ptr2->next;
        if(ptr2==NULL)
        {
            ptr2=temp2;
            adjlist[dest]=ptr2;
        }
        else
            ptr2->next=temp2;
    }
   for (int i=0;i<N;i++)
   {
       cout<<"List of "<< i <<"is: ";
       node *temp=adjlist[i];
       while(temp!=NULL)
       {
           cout<<adjlist[i]<<" -> "<<temp->dest<<"|"<<temp->cost;
           temp=temp->next;
       }
       cout<<"\n";
   }
}
