#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n][n];
    int dist[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<0;j++)
            arr[i][j]=0;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        arr[u][v]=w;
        //arr[v][u]=w;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]!=0)
                dist[i][j]=arr[i][j];
            else if(i==j)
                dist[i][j]=0;
            else
                dist[i][j]=INT_MAX;
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX)
                {
                    if(dist[i][j]>dist[i][k]+dist[k][j])
                        dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INT_MAX)
                cout<<"INF";
            else
                cout<<dist[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
