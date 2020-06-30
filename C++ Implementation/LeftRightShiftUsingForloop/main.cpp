#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

int main()
{
    int n,i,t;
    signed long x,j,k;
    cout<<"enter size";
    cin>>n;
    int a[n];
    cout<<"enter elements";
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<"elements rotate by";
    cin>>k;
    if(k<0)
        {
           x=abs(k%=n);
            for(j=0;j<x;j++)
            {
                t=a[0];
                for(i=0;i<n-1;i++)
                    {
                        a[i]=a[i+1];
                    }
                a[n-1]=t;
            }
        }
    else
    {
        k%=n;
        for(j=0;j<k;j++)
            {
                t=a[n-1];
                for(i=n-1;i>0;i--)
                    {
                        a[i]=a[i-1];
                    }
                a[0]=t;
            }
    }
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}
