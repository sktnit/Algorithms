#include <iostream>

using namespace std;

//Sorting Algorithm
Coordinate* MergeSort(Coordinate a[],int i,int j, bool (*f)(Coordinate p1,Coordinate p2))
{
    if (i==j)
        return a;
    else
    {
        int mid = (i+j)/2;
        MergeSort(a,i,mid,f);
        MergeSort(a,mid+1,j,f);
        Merge(a,i,mid,j,f);
        return a;
    }
}
//Merge Algorithm
Coordinate* Merge(Coordinate a[],int i,int mid, int j, bool (*f)(Coordinate ,Coordinate))
{
    int p,q;
    int n1=mid - i + 1;
    int n2=j - mid;
    Coordinate L[n1+1],R[n2+1];
    for(p=1;p<=n1;p++)
        L[p]=a[p+i-1];
    for(q=1;q<=n2;q++)
        R[q]=a[mid+q];
    p=1;
    q=1;
    L[n1+1]={100001,100001,100001};
    R[n2+1]={100001,100001,100001};
    for(int r=i;r<=j;r++)
    {
        if(f(L[p],R[q]))
        {
            a[r]=L[p];
            p++;
        }
        else
        {
            a[r]=R[q];
            q++;
        }
    }
    return a;
}
//sort along x axis
bool X(Coordinate p,Coordinate q)
{
    return (p.x<q.x || (p.x==q.x && p.y<q.y) || (p.x==q.x && p.y==q.y && p.z<q.z));
}
//sort along y axis
bool Y(Coordinate p,Coordinate q)
{
    return (p.y<q.y ||(p.y==q.y && p.z<q.z));
}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main()
{
  int n;
  int values[] = { 40, 10, 100, 90, 20, 25 };
  qsort (values, 6, sizeof(int), compare);
  for (n=0; n<6; n++)
     printf ("%d ",values[n]);
  return 0;
}
