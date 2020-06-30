#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class HEAP
{
    public:
        vector<int> keys;
        int start=0,end=0;
        void INSERT(int key);
        void heapify(int s,int n);
        void heapify_down(int s ,int n);
        void EXTRACT_MIN();
        void LEVEL_ORDER();
};
void HEAP::heapify(int s,int n)
{
    int p,t;
    if(n>s)
    {
        p=n/2;
        if(keys.at(p)>keys.at(n))
        {
            t=keys.at(p);
            keys.at(p)=keys.at(n);
            keys.at(n)=t;
            heapify(s,p);
        }
    }
}
void HEAP::heapify_down(int s,int e)
{
    int lc=2*s;
    int rc=lc+1;
    int p = s;
    int temp = 0;
    if(lc>e)
        return;

    if(rc<=e){
        if(keys.at(lc)<keys.at(rc)){
            if(keys.at(p)<keys.at(lc))
                return;
            temp = keys.at(lc);
            keys.at(lc) = keys.at(p);
            keys.at(p) = temp;
            heapify_down(lc, e);

        }else{
            if(keys.at(p)<keys.at(rc))
                return;
            temp = keys.at(rc);
            keys.at(rc) = keys.at(p);
            keys.at(p) = temp;
            heapify_down(rc, e);

        }
    }else{
        if(keys.at(p)<keys.at(lc))
                return;
        temp = keys.at(lc);
        keys.at(lc) = keys.at(p);
        keys.at(p) = temp;
        heapify_down(lc, e);
    }
}
void HEAP::INSERT(int key)
{
    if(start==0)
    {
        keys.push_back(0);
        start++;
    }
    keys.push_back(key);
    end++;
    int n=end-start+1;
    heapify(start,n);
}
void HEAP::EXTRACT_MIN()
{
    cout<<keys.at(1)<<endl;
    keys.at(1)=keys.at(end);
    end--;
    cout<<end<<endl;
    int n=end-start+1;
    keys.resize(n+1);
    heapify_down(start,end);
}
void HEAP::LEVEL_ORDER()
{
    int k;
    vector<int>::iterator it;
    for(it=keys.begin()+1;it!=keys.end();it++)
    {
        k=*it;
        cout<<k<<" ";
    }
    cout<<"\n";
}
int main()
{
    int N;
    string Command;
    HEAP v;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>Command;
        if(Command=="INSERT")
        {
            int key;
            cin>>key;
            v.INSERT(key);
        }
        if(Command=="EXTRACT_MIN")
        {
            v.EXTRACT_MIN();
        }
        if(Command=="LEVEL_ORDER")
        {
            v.LEVEL_ORDER();
        }
    }
    return 0;
}
