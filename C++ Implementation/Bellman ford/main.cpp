#include <iostream>
#include <climits>

using namespace std;
class bford
{
public:
    int v=0,e=0,**G;
    void start();
};
void bford :: start()
{
    int n,m;
    cin>>n>>m;
    v=n+1;
    G=new int*[v];
    int E[m*2][2];
    for(int i=0;i<v;i++)
       G[i]=new int[v];
    for(int i=1;i<v;i++)
    {
        G[0][i]=0;
        E[i][0]=0;E[i][1]=i;
        e++;
        for(int j=0;j<v;j++)
            G[i][j]=INT_MAX;
    }
    for(int i=0;i<m;i++)
    {
        int a,b,w,t;
        cin>>a>>b>>w>>t;
        if(t==2)
        {
            G[a][b]=(-w);
            E[e][0]=a;E[e][1]=b;
            e++;
        }
        else if(t==1)
        {
            G[b][a]=w;
            E[e][0]=b;E[e][1]=a;
            e++;
        }
        else if(t==0)
        {
            G[b][a]=w;
            E[e][0]=b;E[e][1]=a;
            e++;
            G[a][b]=(-w);
            E[e][0]=a;E[e][1]=b;
            e++;
        }
    }
    int dist[v];
    int par[v];
    for(int i=0;i<v;i++)
    {
        dist[i]=INT_MAX;
        par[i]=-1;
    }
    dist[0] = 0;
    for(int i=1;i<v;i++)
    {
        for (int j=0;j<e;j++)
        {
            int a=E[j][0];
            int b=E[j][1];
            if(dist[a]!=INT_MAX)
            {
                if(dist[a]+G[a][b]<dist[b])
                {
                    dist[b]=dist[a]+G[a][b];
                    par[b]=a ;
                }
            }
        }
    }
    int flag=0;
    for(int i=0;i<e;i++)
    {
        int a=E[i][0];
        int b=E[i][1];
        if(dist[a]+G[a][b]<dist[b])
            flag=1;
    }
    if(flag==1)
        cout<<"YES";
    else
        cout<<"NO";
}

int main()
{
    bford bell;
    bell.start();
    return 0;
}
