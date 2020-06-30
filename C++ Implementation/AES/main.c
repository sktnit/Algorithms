#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<openssl/aes.h>

void aes(int ,char** );
void des(int ,char** );
void tripledes(int , char** );

void aes_cbc(int argc,char* arr[],int keysize)
{
	unsigned char *key;
	unsigned char *plaintext;
	unsigned char *iv = (unsigned char *)"0123456789012345";
	if (keysize==128)
		key = (unsigned char *)"0123456789012345";
	if (keysize==192)
		key = (unsigned char *)"012345678901234567890123";
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
	const size_t l = ((bfsize + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
	unsigned char cipher[l];
	AES_KEY ekey;
	if(arr[2]=="enc")
    	{
		AES_set_encrypt_key(key, keysize, &ekey);
        	AES_cbc_encrypt(plaintext, cipher , bfsize, &ekey, iv, AES_ENCRYPT);
        	const unsigned char * p = (const unsigned char*)cipher;
        	size_t i = 0;
        	for (; i<sizeof(cipher);++i)
        		fprintf(f_out,"%X ", *p++);

    	}
    	else if(arr[2]=="dec")
    	{
        	AES_set_encrypt_key(key, keysize, &ekey);
        	AES_cbc_encrypt(plaintext, cipher , bfsize, &ekey, iv, AES_DECRYPT);
        	const unsigned char * p = (const unsigned char*)cipher;
        	size_t i = 0;
        	for (; i<sizeof(cipher);++i)
        	fprintf(f_out,"%X ", *p++);
    	}
	fclose(f_in);
	fclose(f_out);
}

void aes_ecb(int argc,char* arr[],int keysize)
{
	unsigned char *key;
	unsigned char *plaintext;
	if (keysize==128)
		key = (unsigned char *)"0123456789012345";
	if (keysize==192)
		key = (unsigned char *)"012345678901234567890123";
	FILE *f_in,*f_out;
	f_in=fopen(arr[10],"r");
	if(f_in==NULL)
	{
		exit(1);
	}
	f_out=fopen(arr[12],"w");
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
	const size_t l = ((bfsize + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
	unsigned char cipher[l];
	if(arr[2]=="enc")
    	{
		AES_KEY ekey;
		AES_set_encrypt_key(key, keysize, &ekey);
        	AES_ecb_encrypt(plaintext, cipher, &ekey, AES_ENCRYPT);
        	const unsigned char * p = (const unsigned char*)cipher;
        	size_t i = 0;
        	for (; i<sizeof(cipher);++i)
        		fprintf(f_out,"%X ", *p++);

    	}
    	else if(arr[2]=="dec")
    	{
        AES_KEY ekey;
        AES_set_encrypt_key(key, keysize, &ekey);
        AES_ecb_encrypt(plaintext, cipher, &ekey, AES_DECRYPT);
	const void* pv=
        const unsigned char * p = (const unsigned char*)cipher;
        size_t i = 0;
        for (; i<sizeof(cipher);++i)
        	fprintf(f_out,"%X ", *p++);
    	}
	fclose(f_in);
	fclose(f_out);
}

void aes(int argc,char* arr[])
{
    int keylength=0;
    if (arr[5]=="-m" && (arr[6]=="ecb" || arr[6]=="cbc" || arr[6]=="ctr"))
    {
        if(arr[7]=="-k" && (arr[8]=="56" || arr[8]=="112" || arr[8]=="128" || arr[8]=="168" || arr[8]=="192"))
            if(arr[9]=="-i" && arr[11]=="-o")
            {
                keylength=atoi(arr[8]);
                if (arr[6]=="cbc")
                    aes_cbc(argc,arr,keylength);
		if (arr[6]=="ecb")
		    aes_ecb(argc,arr,keylength);
            }
    }
}

void des(int argc, char** arr)
{

}

void tripledes(int argc, char **arr)
{

}
int main(int argc, char* arg[])
{
    if(arg[0]=="./a.out")
    {
        if(arg[1]== "-o" && (arg[2]=="enc" || arg[2]=="dec"))
        {
            if (arg[3]== "-a" && (arg[4]=="aes"||arg[4]=="des"||arg[4]=="3des"))
            {
                if(arg[4]=="aes")
                    aes(argc,arg);
                if (arg[4]=="des")
                    des(argc,arg);
                if (arg[4]=="3des")
                    tripledes(argc,arg);
            }
        }
    }
}


