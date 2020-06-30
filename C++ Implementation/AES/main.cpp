# include "VirtualAES.h"
#include <iostream>
using namespace std;
int main()
{
unsigned char  key [key_128]="very strong key";
unsigned char plaintext[BLOCK_SIZE]="this is a test";
unsigned char ciphertext[BLOCK_SIZE];
unsigned char decrypted[BLOCK_SIZE];
aes_ctx_t* ctx;
virtualAES::Initialize();
ctx=vitualAES::AllocateCTX(key,sizeof(key));
vitualAES::Encrypt(ctx,plaintext,ciphertext);
cout<<"Encrypted data in ascii:"<<ciphertext<<endl;
vitualAES::Decrypt(ctx,plaintext,decrypted);
cout<<"DEcrypted data in ascii:"<<decrypted<<endl;
getchar();
return 0;
}
