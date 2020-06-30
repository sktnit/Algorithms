#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;

int deletek(int distance[],int v[],int n);
void decreasekey(int distance[],int v[],int position);
int searchkey(int v[],int i,int n);
class node
{
    public:
    int v;
    int e;
    node *next;
};

int main() {

    int V,E,source,V1,V2,w1;
    cin>>V;
    int bc[V];
    cin>>E;
    cin>>source;
    node *adjcost[V];
    for(int i=0;i<V;i++)
        adjcost[i]=NULL;

for(int i=0;i<E;i++)
     {
    node *node1=new node;
    node *node2=new node;
      node *p,*q;
    cin>>V1>>V2>>w1;
      p=adjcost[V1];
      node1->v=V2;
      node1->e=w1;
      node1->next=NULL;

       while(p && p->next)
         p=p->next;

      if(!p)
      {
          p=node1;
       adjcost[V1]=p;
      }
      else
          p->next=node1;

       q=adjcost[V2];
        node2->v=V1;
        node2->e=w1;
        node2->next=NULL;
     while(q && q->next)
         q=q->next;

      if(!q)
      {
          q=node2;
       adjcost[V2]=q;
      }
      else
          q->next=node2;

     }

    int previous[V],path[V];
    int distance[V],v[V+1];
    int maximum = INT_MAX;
    for(int i=0;i<V;i++)
        {
        distance[i]=maximum;
        previous[i]=-1;
        v[i+1]=i;
        path[i]=1;
    }

      distance[source]=0;
      v[1]=source;
      v[source+1]=0;
      int temp=V+1,po;
   while(temp!=1)
{
int u=deletek(distance,v,temp);
temp--;
node *q=adjcost[u];

while(q)
{
    int i=q->v;
 int po=searchkey(v,i,V+1);
if(distance[i] > distance[u]+q->e)
  {
    distance[i]=distance[u]+q->e;
    previous[i]=u;
   path[i]=path[u];
   decreasekey(distance,v,po);
 }
else if(distance[i] == distance[u]+q->e)
      path[i]+=path[u];
 q=q->next;
}
}
  for(int i=0;i<V;i++)
  {   if(previous[i]==-1 && i!=source)
        path[i]=0;
      cout<<path[i]<<" ";
}
}

int searchkey(int v[],int i,int n)
{
    int position=1;
while(position<n)
{
    if(i==v[position])
 break;
position++;
}
return position;
}

void decreasekey(int distance[],int v[],int position)
{
int temp=v[position];
int temp1=distance[temp];

while(position>1 && temp1<distance[v[position/2]])
{
    v[position]=v[position/2];
position=position/2;}
v[position]=temp;
}

int deletek(int distance[],int v[],int n)
{
    int min=v[1],position=1,temp1,temp;
    v[1]=v[n-1];
    temp1=distance[v[1]];
temp=v[1];
position=2*position;
while(position<n-1)
{

if(position < n-1 && distance[v[position]] > distance[v[position+1]])
 position+=1;

if(temp1>distance[v[position]])
 v[position/2]=v[position];
else
break;

position=2*position;

}
v[position/2]=temp;
return min;
}


