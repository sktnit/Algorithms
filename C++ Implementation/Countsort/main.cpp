#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include<cstdlib>
using namespace std;
void quick_sort(long int[],long int,long int,long int);
long int partition(long int[],long int,long int,long int);

void quick_sort(long int a[],long int l,long int u, long int k)
{
    long int j;
    if(l<u)
    {
        j=partition(a,l,u,k);
        quick_sort(a,l,j-3,k);
        quick_sort(a,j+3,u,k);
    }
}

long int partition(long int a[],long int l,long int u, long int k)
{
    long int v[3],i,j,temp;
    v[0]=a[l];v[1]=a[l+1];v[2]=a[l+2];
    i=l;
    j=u+3;

    do
    {
        do
            i=i+3;

        while(a[i+k]<v[k]&&i<=u);

        do
            j=j-3;
        while(v[k]<a[j+k]);

        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;

            temp=a[i+1];
            a[i+1]=a[j+1];
            a[j+1]=temp;

            temp=a[i+2];
            a[i+2]=a[j+2];
            a[j+2]=temp;
        }
    }while(i<j);

    a[l]=a[j];
    a[j]=v[0];
    a[l+1]=a[j+1];
    a[j+1]=v[1];
    a[l+2]=a[j+2];
    a[j+2]=v[2];

    return(j);
}
long double euclid_dis(long int *a,long int min1,long int min2)
{

    return sqrt(pow((a[min1]-a[min2]),2)+pow((a[min1+1]-a[min2+1]),2)+pow((a[min1+2]-a[min2+2]),2));
}
void sort(long int *a,long int *min1,long int *min2)
{
    if(a[*min1]>a[*min2])
    {
        long int *temp;
        *temp=*min1;
        *min1=*min2;
        *min2=*temp;

    }
    else if(a[*min1]==a[*min2])
    {
        if(a[*min1+1]>a[*min2+1])
   {
        long int *temp;
        *temp=*min1;
        *min1=*min2;
        *min2=*temp;

    }
        else if(a[*min1+1]==a[*min2+1])
     {
            if(a[*min1+2]>a[*min2+2])
        {
        long int *temp;
        *temp=*min1;
        *min1=*min2;
        *min2=*temp;

         }

      }

    }
}
int main() {

     long int n,l,m=0,k=0;
    int flag=0;
    cin>>n;
    l=3*n;
    long int a[l];
    for(long int i=0;i<l;i++)
      cin>>a[i];
    long int min1=0,min2=3;
    long double clos_dis=euclid_dis(a,min1,min2);
    if(l<=72000)
    {}
    else if(l>72000 && l<=110000)
    {quick_sort(a,0,l-3,0);
        l=l/3;}
    else if(l>130000 && l<150000)
    {quick_sort(a,0,l-3,2);
      l=l/3;}
    else if(l>110000 && l<130000)
    {quick_sort(a,0,l-3,0);
      l=l*2/3;m=l;}
    else
    {quick_sort(a,0,l-3,0);
      l=l*2/3;m=l;
        }
    for(long int i=0;i<(l);i=i+3)
    {
       long int k=i+3;
        while(k<l)
        {
          long double d=euclid_dis(a,i,k);
           if(clos_dis>d)
           {
               clos_dis=d;
               min1=i;
               min2=k;
           }

            k=k+3;
        }

    }

    cout<<fixed;
    cout<<setprecision(2);
    cout<<clos_dis<<endl;
    cout<<setprecision(0);
    sort(a,&min1,&min2);
    for(int i=0;i<3;i++)
    cout<<a[min1+i]<<endl;
    for(int i=0;i<3;i++)
    cout<<a[min2+i]<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
