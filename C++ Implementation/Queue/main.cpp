#include<iostream>
#include<queue>
#include <cstdlib>
#include <climits>
using namespace std;
int main()
{
	int n,x;
	signed d;
	cin>>n;
	queue<int> q;
	for(int i=0; i<n; i++){
	    int p;
	    cin>>p;
	    q.push(p);
	}
	cin>>d;
	if(d>0)
    {
        d%=n;
        for(int i=0; i<d; i++)
            {
                int tmp = q.front();
                q.pop();
                q.push(tmp);
            }
        while(!q.empty())
            {
                cout<<q.front()<<" ";
                q.pop();
            }
    }
	else
	{
	    x=abs(d);
	    d%=n;

	}
	return 0;
}
