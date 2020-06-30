#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<openssl/crypto/des/des.h>

void des(int ,char** );

void des_cbc(int argc,char* arr[],int keysize)
{
	unsigned char *key=(unsigned char *)"0123456";;
	unsigned char *iv = (unsigned char *)"0123456789012345";
	unsigned char *plaintext;
	DES_cblock initvec;
	DES_key_schedule ekey;
	DES_set_key((C_block*)key, &ekey);
	FILE *f_in,*f_out;
	f_in=fopen(arr[10],"r");
	if(f_in==NULL)
	{
		exit(1);
	}
	f_out=fopen(arr[12],"w+");
	if(f_out==NULL)
	{
		fclose(f_in);
		exit(2);
	}
	fseek(f_in,0L, SEEK_END);
	long bfsize=ftell(f_in);
	rewind(f_in);
	plaintext=malloc(sizeof(char)*(bfsize + 1));
	fread(plaintext,sizeof(char), bfsize, f_in);
	const size_t l = ((bfsize + DES_BLOCK_SIZE) / DES_BLOCK_SIZE) * DES_BLOCK_SIZE;
	unsigned char cipher[l];
	if(arr[2]=="enc")
    	{
        	DES_cbc_encrypt(plaintext, cipher , bfsize,&ekey,(DES_cblock*)iv, DES_ENCRYPT);
            fwrite(cipher,sizeof(char),l,f_out);
    	}
    	else if(arr[2]=="dec")
    	{
        	DES_cbc_encrypt(plaintext, cipher , bfsize, &ekey,(DES_cblock*) iv, AES_DECRYPT);
        	fwrite(cipher,sizeof(char),l,f_out);
    	}
	fclose(f_in);
	fclose(f_out);
}


void des(int argc, char** arr)
{
    int keylength=0;
    if (arr[5]=="-m" && (arr[6]=="ecb" || arr[6]=="cbc" || arr[6]=="ctr"))
    {
        if(arr[7]=="-k" && (arr[8]=="56" || arr[8]=="112" || arr[8]=="128" || arr[8]=="168" || arr[8]=="192"))
            if(arr[9]=="-i" && arr[11]=="-o")
            {
               keylength=atoi(arr[8]);
                if (arr[6]=="cbc")
                    des_cbc(argc,arr,keylength);
                if (arr[6]=="ecb")
                    des_ecb(argc,arr,keylength);
            }
    }
}

int main(int argc, char* arg[])
{
    if(arg[0]=="./a.out")
    {
        if(arg[1]== "-o" && (arg[2]=="enc" || arg[2]=="dec"))
        {
            if (arg[3]== "-a" && (arg[4]=="des")
            {
                    des(argc,arg);
            }
        }
    }
}
