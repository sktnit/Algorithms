#include <iostream>
#include<cstring>
#include<string>

using namespace std;

int main() {

    int l,n,i,j,k,count=0,count1=0;
    char a[n][n],s[10];
    //cout<<"enter size";
    cin>>n;
    //cout<<"enter characters in an array";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin>>a[i][j];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j];
        }
    }

    cout<<"enter string";
    for(i=0;i!='\0';i++)
    cin>>s[i];
    l=strlen(s);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            k=0;
            while(l)
            {
            if(a[i][j]==s[k])
            {
                count++;
                k++;
                j++;

            }
                if(count==l)
                {
                    count1++;
                    count=0;

                }
                else j++;
                l--;
            }
           cout<<"string match horizontally"<<count1;
return 0;
    }
