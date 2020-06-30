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
    int S,T;
    cin>>S>>T;
    node *adjlist[N+1];
    for (int i=0;i<N;i++)
        adjlist[i]=NULL;

    //Create adjacency list
    for (int i=0;i<M;i++)
    {
        int start,dest,wt;
        cin>>start>>dest>>wt;
        node *temp=new node;
        temp->dest=dest;
        temp->cost=wt;
        temp->next=NULL;
        node *ptr;
        ptr=adjlist[start];
        while(ptr!=NULL && ptr->next!=NULL)
            ptr=ptr->next;
        if(ptr==NULL)
        {
            ptr=temp;
            adjlist[start]=ptr;
        }
        else
            ptr->next=temp;
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
