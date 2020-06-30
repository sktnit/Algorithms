#include <iostream>

using namespace std;

int main()
{
    int T,sl,pl;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        cin>>pl>>sl;
        char str[sl+1],pat[pl+1];
        cin>>pat>>str;
        int pi[pl];

        pi[0]=0;
        int j=0,i=1;
        while(j<pl)
        {
            if(pat[j]==pat[i])
            {
                pi[i]=++j;
                i++;
            }
            else{
                if(j==0)
                {
                    pi[i]=0;
                    i++;
                }
                else
                {
                    j=pi[j-1];
                }
            }
        }
        i=0;
        j=0;
        while(i<sl)
        {
            if(str[i]==pat[j])
            {
                j++;
                i++;
            }
            if(j==pl)
            {
                cout<<i-j;
                j=pi[j-1];
            }
            else if(i<sl)
            {
                if(str[i]!=pat[j])
                {
                    if(j!=0)
                        j=pi[j-1];
                    else
                        i++;
                }
            }
        }
    }
    return 0;
}
