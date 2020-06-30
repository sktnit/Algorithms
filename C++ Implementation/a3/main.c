#include <openssl/des.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	DES_cblock cb1 = { 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE };
	DES_cblock cb2 = { 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE };
	DES_cblock cb3 = { 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE, 0xAE };

	DES_key_schedule ks1;
	//DES_key_schedule ks2;
	//DES_key_schedule ks3;//aes.c wala usme do modes hai cbc and

	DES_cblock cblock = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

	char string[] = "I am a software developer";

	printf("Plain Text : %s\n",string);
	int stringLen=sizeof(string);

	char* cipher = (char *) malloc(32);
	char* text = (char *) malloc(strlen(string));
	memset(cipher,0,32);
	memset(text,0,stringLen);


	DES_set_odd_parity(&cblock);

	if (DES_set_key_checked(&cb1, &ks1)){ //|| DES_set_key_checked(&cb2, &ks2) || DES_set_key_checked(&cb3, &ks3)) {
		printf("Key error, exiting ....\n");
		return 1;
	}

	DES_cbc_encrypt(string, cipher, strlen(string), &ks1, /*&ks2, &ks3,*/&cblock, 1);

	printf("Encrypted : %s+\n",cipher);
	memset(cblock,0,sizeof(DES_cblock));
	DES_set_odd_parity(&cblock);

	DES_cbc_encrypt(cipher, text, strlen(cipher), &ks1,/* &ks2, &ks3,*/&cblock,0);

	printf("Decrypted : %s\n",text);
}
