#include <iostream>
#include<cstring>
#include<string>
#define MAX 100
using namespace std;

int rowNum[] = { 0, 1, 1 };
int colNum[] = { 1, 0, 1 };

bool found=false;
bool isSafe(int row,int col, int n)
{
    return (row >= 0) && (row < n) && (col >= 0) && (col < n);
}
int findwords(char mat[][MAX],int n, int row, int col, string word)
{
    if (mat[row][col] != word[0])
    {
        return 0;
    }
    int len = word.length();
    int counts=0;
    for (int dir = 0; dir < 3; ++dir)
    {
        if(dir==0||dir==1)
        {
            int rd = (row + rowNum[dir])%n;
            int cd = (col + colNum[dir])%n;
            int k;
            for (k = 1; k <= len - 1; k++)
            {
                if (!isSafe(rd, cd, n))
                {
                    break;
                }
                if (!(mat[rd][cd] == word[k]))
                {
                    break;
                }
                else
				rd = (rd + rowNum[dir])%n;
				cd = (cd + colNum[dir])%n;
			}
			if (k == len)
            {
				counts++;
				found = true;
			}
        }
        else
        {
            int rd = (row + rowNum[dir]);
            int cd = (col + colNum[dir]);
            int k;
            for (k = 1; k <= len - 1; k++)
            {
                if (!isSafe(rd, cd, n))
                {
                    break;
                }
                if (!(mat[rd][cd] == word[k]))
                {
                    break;
                }
                else
				rd = rd + rowNum[dir];
				cd = cd + colNum[dir];
			}
			if (k == len)
            {
				counts++;
				found = true;
			}
        }
    }
    return counts;
}

int findWordCount(char mat[][MAX],int n, string pattern)
{
    int counts=0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // occurrence of first character in matrix
            if (mat[i][j] == pattern[0])
            {
                if(pattern.length()==1) counts=counts+1;
                else counts=counts+findwords(mat,n,i,j,pattern);
            }
        }
    }
   return counts;
}

int main()
{
	int n,k,tc=0,counts[MAX];
	cout<<"Enter test cases";
	cin>>k;
	while(tc<k)
    {
        counts[tc]=0;
        cin>>n;
        char mat[100][100];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                cin>>mat[i][j];
            }
        string pattern;
        cin>>pattern;
        counts[tc]=findWordCount(mat,n,pattern);
        tc++;
    }
    for(int i=0;i<k;i++)
        cout<<counts[i]<<"\n";
	return 0;
}
