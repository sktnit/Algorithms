#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    int tsize;//text size
    cin>>tsize;
    char text[tsize];
    int psize;//pattern size
    cin>>psize;
    char pattern[psize];
    cin.getline(text,tsize);// for new line cin.getline(text,tsize,'\n');
    cin.getline(pattern,psize);
    int M=strlen(text);
    int N=strlen(pattern);
    int flag=0;
    for (int i=0;i<M-N;i++)
    {
        int j;
        for ( j=0;j<N;j++)
            if(pattern[j]!=text[i+j])
                break;
        if(j==N)
            flag=1;
    }
    if (flag==1)
        cout<<"yes";
    return 0;
}
