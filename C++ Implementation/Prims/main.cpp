#include <vector>
#include <iostream>
#include <set>
#include <list>
#include <climits>
using namespace std;

struct Edge
{
    int dest, weight;
};

int main()
{
    int num_of_v, num_of_e, vr;
    cin >> num_of_v >> num_of_e;
    vector<list<Edge> > adj_list(num_of_v);
    //vector<list<Edge> > mst_list(num_of_v);
    bool visited[num_of_v];
    for(int i=0;i<num_of_v;i++)
        visited[i]=false; //initially every nodes is not visited
    set<pair<int, int> > T;
    set<int> A;
    vector<Edge> mst;
    vector<int> min_cost(num_of_v,INT_MAX);//initially min_cost of each node is infinity
    //for undirected graph.
    for (int i = 0; i < num_of_e; ++i)
    {
        int x,y,w;//x(start), y(end) are nodes with edge weight w.
        cin >> x >> y >> w;
        adj_list[x].push_back(Edge{y, w});
        adj_list[y].push_back(Edge{x, w});//for directed this line should be comment
    }
    cin >> vr;//starting vertex
    min_cost[vr] = 0;
    T.insert(make_pair(0,vr));//source vert inserted into set T
    visited[vr]=true;// visited of source is true
    long mst_cost = 0;//intial mst cost is 0.
    while (!T.empty())
    {
        int temp = T.begin()->second;
        mst_cost += min_cost[temp];
        A.insert(temp);
        visited[temp]=true;
        T.erase(T.begin());//delete vertex with minimum cost which is always at top of set T
        list<Edge> li=adj_list[temp];
        for (list<Edge>::iterator i=li.begin();i!=li.end();i++)
        {
            if (A.count(i->dest) == 1)
                continue;//skip if already in the set A
            int v=i->dest;
            int weight = i->weight;
            //update cost of vertices reachable from deleted vertex
            if (min_cost[v]>weight)
            {
                if(min_cost[v]!=INT_MAX)
                T.erase(T.find(make_pair(min_cost[v], v)));
                min_cost[v]=weight;
                T.insert(make_pair(min_cost[v], v));
            }
        }
        if(T.empty())//for disconnected graph
        {
            for (int i=0; i<num_of_v; i++)
                if (visited[i] == false)
                {
                    min_cost[i]=0;
                    T.insert(make_pair(min_cost[i],i));
                }
        }
    }
    cout << mst_cost;
    return 0;
}
