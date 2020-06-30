#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include<cstdlib>
using namespace std;

long double Small(long int a[], int l)
{
    long double min = dis(a,0,3);;
    for(long int i=0;i<(l);i=i+3)
    {
       long int k=i+3;
        while(k<l)
        {
          long double d=dis(a,i,k);
           if(min>d)
           {
               min=d;
               min1=i;
               min2=k;
           }

            k=k+3;
        }
    }
    return min;
}

long double stripClosest(long int strip[], int n, long double d)
{
    long double min = d;
    for(long int i=0;i<n;i=i+3)
    {
       long int k=i+3;
        while(k<n)
        {
          long double d=dis(strip,i,k);
           if(min>d)
           {
               min=d;
               min1=i;
               min2=k;
           }

            k=k+3;
        }
    }
    return min;
}

long double Utility(long int a[],long int l)
{
    long int n=l/3;
    if (n<= 3)
        return Small(a, l);
    else{
    long int mid = n/2;
    mid=mid*3;
    long double dl = Utility(a, mid);
    long int temp1=min1,temp2=min2;
    long  double dr =Utility(a+mid,n-mid);
    long int temp3=min1,temp4=min2;
    long double d;
    if(dl<dr)
    {
        d=dl;
        min1=temp1;
        min2=temp2;

    }
    else{
        d=dl;
        min1=temp3;
        min2=temp4;
    }
    long int strip[l];
    long int j = 0;
    for (long int i = 0; i < l; i+=3)
        if (abs(a[i] - a[mid])< d)
           {
               strip[j] = a[i];j++;
           }
     if(d<stripClosest(strip, j, d))
         return d;
     else
        return stripClosest(strip, j, d);
    }
}
long double Closest(long int a[],long int l)
{
    Qsort(a,0,l-1,0);
    return Utility(a,l);
}

long double dis(long int *a,long int x,long int y)
{
    return sqrt(pow((a[x]-a[y]),2)+pow((a[x+1]-a[y+1]),2)+pow((a[x+2]-a[y+2]),2));
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
long int Partition(long int a[],long int i,long int j, long int axis)
{
    long int arr[3],p,q,temp;
    arr[0]=a[i];
    arr[1]=a[i+1];
    arr[2]=a[i+2];
    p=i;
    q=j+3;

    do
    {
        do
        p=p+3;
        while(a[p+axis]<arr[axis]&& p<=j);
        do
            q=q-3;
        while(arr[axis]<a[q+axis]);
        if(p<q)
        {
            temp=a[p];
            a[p]=a[q];
            a[q]=temp;

            temp=a[p+1];
            a[p+1]=a[q+1];
            a[q+1]=temp;

            temp=a[p+2];
            a[p+2]=a[q+2];
            a[q+2]=temp;
        }
    }while(p<j);

    a[i]=a[q];
    a[q]=arr[0];
    a[i+1]=a[q+1];
    a[q+1]=arr[1];
    a[i+2]=a[q+2];
    a[q+2]=arr[2];

    return q;
}
void Qsort(long int a[],long int i,long int j, long int axis)
{
    long int mid;
    if(i<j)
    {
        mid=Partition(a,i,j,axis);
        Qsort(a,i,mid-3,axis);
        Qsort(a,mid+3,j,axis);
    }
}

int main() {
    long int n,l;
    cin>>n;
    l=3*n;
    long int a[l];
    for(long int i=0;i<l;i++)
      cin>>a[i];
    long int x=0,y=3;
    long double d=dis(a,x,y);
    long int m=0,k=0;
    if(l>72000 && l<=110000)
    {
        Qsort(a,0,l-3,0);
        l=l/3;
    }
    else if(l>130000 && l<150000)
    {
        Qsort(a,0,l-3,1);
        l=l/3;
    }
    else if(l>110000 && l<130000)
    {
        Qsort(a,0,l-3,2);
        l=l*2/3;m=l;
    }
    else
    {
        Qsort(a,0,l-3,0);
        l=l*2/3;m=l;
    }
    for(long int i=0;i<(l);i=i+3)
    {
       long int k=i+3;
        while(k<l)
        {
          long double d2=dis(a,i,k);
           if(d>d2)
           {
               d=d2;
               x=i;
               y=k;
           }

            k=k+3;
        }

    }

    cout<<fixed;
    cout<<setprecision(2);
    cout<<d<<endl;
    cout<<setprecision(0);
    sort(a,&x,&y);
    for(int i=0;i<3;i++)
    cout<<a[x+i]<<endl;
    for(int i=0;i<3;i++)
    cout<<a[y+i]<<endl;
    return 0;
}
