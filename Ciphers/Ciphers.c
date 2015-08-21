#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main()
{
	char *encryptViginere(const char *txt, const char *key);
	char *decryptViginere(const char *txt, const char *key);
	char *txt = (char *)calloc(128,sizeof(char)), *key = (char *)calloc(128,sizeof(char));
	int c = 0;
	printf("Enter plain text:: ");	//txt lim = 127 chars
	scanf("%[^\n]s",txt);
	getchar();
	printf("Enter key:: ");
	scanf("%[^\n]s",key);
	getchar();
	printf("Encrypted:: %s\nDecrypted:: %s\nContinue(Y/N)",encryptViginere((const char *)txt,(const char *)key),decryptViginere((const char *)encryptViginere(txt,key),key));
	scanf("%s",&c);
	getchar();
	if(c=='Y'||c=='y')
		return main();
}
char *encryptMorseCode(const char *txt, const char key1, const char key2)
{
	char *morseCode(const char*txt, const char key1, const char key2, int mode);
	return morseCode(txt,key1,key2,1);
}
char *DecryptMorseCode(const char *txt, const char key1, const char key2)
{
	char *morseCode(const char*txt, const char key1, const char key2, int mode);
	return morseCode(txt, key1, key2, 0);
}
char *morseCode(const char *txt, const char key1, const char key2, int mode)
{
}
char *encryptViginere(const char *txt,const char *key)
{
	char *keyedViginere(const char *txt, const char *key, int mode);
	return keyedViginere(txt,key,1);
}
char *decryptViginere(const char *txt, const char *key)
{
	char *keyedViginere(const char *txt, const char *key, int mode);
	return keyedViginere(txt,key,0);
}
char *keyedViginere(const char *txt,const char *key, int mode) //Standard Viginere Cipher (only works with letters & assumes all input is correct)
{
	#define isUppercase(x) ((char)x>='A' && (char)x<='Z')
	#define isLowercase(x) ((char)x>='a' && (char)x<='z')
	int keyLen = strlen(key), txtLen = strlen(txt), cnt = 0; //Optimize later
	char *out = (char *)calloc(txtLen+1,sizeof(char));
	short *shifts = (short *)calloc(keyLen,sizeof(short));
	while(cnt < keyLen)
	{
		shifts[cnt] = (isUppercase(key[cnt])) ? key[cnt] - 'A' : (isLowercase(key[cnt])) ? key[cnt] - 'a' : 0; //Shift values for viginere
		cnt++;
	}
	cnt = 0;
	if(mode)
	{
		#define cipherUppercase(x,y) (char)((x-'A'+y)%26+'A')     //computes cipher on uppercase
		#define cipherLowercase(x,y) (char)((x-'a'+y)%26+'a')     //computes cipher on lowercase
		while (cnt < txtLen)
		{ 
			out[cnt] = (isUppercase(txt[cnt])) ? cipherUppercase(txt[cnt],shifts[cnt%keyLen]): (isLowercase(txt[cnt])) ? cipherLowercase(txt[cnt],shifts[cnt%keyLen]):txt[cnt];
			cnt++;
		}
		free(shifts);
	}
	else
	{
		#define decipherUppercase(x,y) ((x-y)< 0 )? (char)(26+(x-y)-'A')%26+'A' : (char)((x-'A'-y)%26+'A')     //computes cipher on uppercase
		#define decipherLowercase(x,y) ((x-y)< 0 )? (char)(26+(x-y)-'a')%26+'a' : (char)((x-'a'-y)%26+'a')     //computes cipher on lowercase
		while (cnt < txtLen)
		{
			out[cnt] = (isUppercase(txt[cnt])) ? decipherUppercase(txt[cnt], shifts[cnt%keyLen]) : (isLowercase(txt[cnt%keyLen])) ? decipherLowercase(txt[cnt], shifts[cnt%keyLen]) : txt[cnt];
			cnt++;
		}
		free(shifts);
	}
	return out;
}