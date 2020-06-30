#include <stdio.h>
#include <string.h>

int main()
{
    int n,i,j,k,l;
    int count = 0,temp,count1 = 0;
    char arr[100][100],str[]="";
    printf("Enter the size");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                {
                    fflush(stdin);
                    scanf("%c",&arr[i][j]);
                }
        }
    for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                {
                    fflush(stdin);
                    printf("%c ",arr[i][j]);
                }
            printf("\n");
        }
    printf("\nEnter a substring : ");
    scanf("%s",str);
    l = strlen(str);
    temp=l;
    for(i=0;i<n;i++)
 {
        for(j=0;j<n;j++)
        {
            k=0;
            while(l)
            {
                if(arr[i][j]==str[k])
                {
                    count++;
                  i++;
                  k++;
                }
                if(count==l)
                {
                    count1++;
                    count=0;
                }

                l--;
            }
        }
        printf("%s occurs %d times", str, count1);
    //printf("%s occurs %d times", str, count1);
        return 0;
}
}
