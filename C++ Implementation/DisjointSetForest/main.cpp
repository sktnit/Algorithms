#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Disjoint
{
    public:
        vector< int > V;
        void MakeSet(int N);
        void UNION(int A, int B);
        int FIND(int A);
        int CC();
};

void Disjoint::MakeSet(int N)
{
    for(int i=1;i<=N;i++)
    {
        V.push_back(i);
        Parent[i]=i;
        Rank[i]=0;
    }
}

void Disjoint::UNION(int A,int B)
{
    int root1=FIND(A);
    int root2=FIND(B);
    if(Rank[root1]>Rank[root2])
        Parent[root2]=root1;
    else
        Parent[root1]=root2;
    if(Rank[root1]==Rank[root2])
        Rank[root2]=Rank[root2]+1;
}

int Disjoint::FIND(int A)
{
    if(Parent[A]!=A)
       Parent[A]= FIND(Parent[A]);
    return Parent[A];

}

int Disjoint::CC()
{
    unordered_map<int ,int>:: iterator it;
    int count=0;
    for(it=Parent.begin();it!=Parent.end();it++)
    {
        if(it->first==it->second)
            count++;
    }
    return count;
}

int main()
{
    int N,Q;
    string op;
    Disjoint obj;
    cin>>N>>Q;
    obj.MakeSet(N);
    for(int i=1;i<=Q;i++)
    {
        cin>>op;

        if(op=="UNION")
        {
            int A,B;
            cin>>A>>B;
            obj.UNION(A,B);
        }
        if(op=="FIND")
        {
            int A,Root;
            cin>>A;
            Root=obj.FIND(A);
            cout<<Root<<endl;
        }
        if(op=="CC")
        {
            int count;
            count=obj.CC();
            cout<<count<<endl;
        }
    }
    return 0;
}
