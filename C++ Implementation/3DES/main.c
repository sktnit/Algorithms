#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<openssl/des.h>

void tripledes(int , char** );


void tripledes(int argc, char **arr)
{
    int keylength=0;
    if (arr[5]=="-m" && (arr[6]=="ecb" || arr[6]=="cbc" || arr[6]=="ctr"))
    {
        if(arr[7]=="-k" && (arr[8]=="56" || arr[8]=="112" || arr[8]=="128" || arr[8]=="168" || arr[8]=="192"))
            if(arr[9]=="-i" && arr[11]=="-o")
            {
                /*keylength=atoi(arr[8]);
                if (arr[6]=="cbc")
                    tripledes_cbc(argc,arr,keylength);
		if (arr[6]=="ecb")
		    tripledes_ecb(argc,arr,keylength);*/
            }
    }
}

int main(int argc, char* arg[])
{
    if(arg[0]=="./a.out")
    {
        if(arg[1]== "-o" && (arg[2]=="enc" || arg[2]=="dec"))
        {
            if (arg[3]== "-a" && arg[4]=="3des")
            {
                    tripledes(argc,arg);
            }
        }
    }
}
