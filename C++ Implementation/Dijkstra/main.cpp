#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;
class Node
{
public:
    int vertex_id;
    int weight;
    Node()
    {
        vertex_id=0;
        weight=0;
    }
    Node(int id, int wt)
    {
        vertex_id=id;
        weight=wt;
    }
};

class HEAP
{
public:
    vector<Node> node;
    int start=0,end=0;
    void INSERT(int id, int wt);
    void heapify(int s,int n);
    void heapify_down(int s ,int n);
    void decrease_key(int value, int p);
    void EXTRACT_MIN();
};
void HEAP::heapify(int s,int n)
{
    int p;
    Node t;
    if(n>s)
    {
        p=n/2;
        if(node[p].weight>node[n].weight)
        {
            t=node[p];
            node[p]=node[n];
            node[n]=t;
            heapify(s,p);
        }
    }
}
void HEAP::heapify_down(int s,int e)
{
    int lc=2*s;
    int rc=lc+1;
    int p = s;
    Node temp;
    if(lc>e)
        return;

    if(rc<=e){
        if(node[lc].weight<node[rc].weight){
            if(node[p].weight<node[lc].weight)
                return;
            temp = node[lc];
            node[lc] = node[p];
            node[p] = temp;
            heapify_down(lc, e);

        }else{
            if(node[p].weight<node[rc].weight)
                return;
            temp = node[rc];
            node[rc] = node[p];
            node[p] = temp;
            heapify_down(rc, e);

        }
    }else{
        if(node[p].weight<node[lc].weight)
                return;
        temp = node[lc];
        node[lc] = node[p];
        node[p] = temp;
        heapify_down(lc, e);
    }
}

void HEAP::decrease_key(int value, int p)
{
    node[p].weight=value;
    heapify(start,p);
}
void HEAP::INSERT(int id,int wt)
{
    if(start==0)
    {
        node.push_back( Node(0,0));
        start++;
    }
    node.push_back( Node(id,wt) );
    end++;
    int n=end-start+1;
    heapify(start,n);
}
void HEAP::EXTRACT_MIN()
{
    node[1]=node[end];
    end--;
    int n=end-start+1;
    node.resize(n+1);
    heapify_down(start,end);
}

class Edge
{
public:
    int vid;
    int weight;
    Edge()
    {
        vid=0;
        weight=0;
    }
    Edge(int id,int wt)
    {
        vid=id;
        weight=wt;
    }
};
class Graph
{
public:
    int V;
    vector< list <Edge> > adjlist;
    void setvertices(int N)
    {
        V=N;
        adjlist.resize(N+1);
        adjlist[0].push_back(Edge(0,0));
    }
    void setedges(int M)
    {
        for(int i=1;i<=M;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            adjlist[a].push_back(Edge(b,c));
            adjlist[b].push_back(Edge(a,c));
        }
    }
    void Dijkstra(int S)
    {
        HEAP Dijk;
        for(int i=1;i<=V;i++)
        {
            Dijk.INSERT(i,INT_MAX);

        }
        Dijk.node[S].weight=0;

    }
};
int main()
{
    int N,M,S;
    cin>>N>>M>>S;
    Graph g;
    g.setvertices(N);
    g.setedges(M);
    g.Dijkstra(S);
    return 0;
}

