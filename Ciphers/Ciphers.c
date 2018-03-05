#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define isUpperCase(x) (((char)x>='A'&&(char)x<='Z')?1:0)
#define isLowerCase(x) (((char)x>='a'&&(char)x<='z')?1:0)
#define isWhat(x) (isUpperCase(x)?0:isLowerCase(x)?1:2)
#define MOD 26
void normalizeKey(char *key){
    int k=0;
    int len=strlen(key);
    while(k<len){
        switch(isWhat(key[k])){
            case 1: key[k]=key[k]-32;
            default: break;
        }
        k++;
    }
}
char *encryptViginere(char *txt,char *key){
    int keyLen = strlen(key), txtLen = strlen(txt), cnt = 0;
    char *out = malloc(txtLen+1*sizeof(char));
    out[txtLen]='\0';
    while(cnt < txtLen){
        switch(isWhat(txt[cnt])){
            case 0:
                if(isUpperCase(key[cnt%keyLen]))
                    out[cnt]=(((txt[cnt]-'A')+(key[cnt%keyLen]-'A'))%MOD)+'A';
                else
                    out[cnt]=txt[cnt];
                break;
            case 1:
                if(isUpperCase(key[cnt%keyLen]))
                    out[cnt]=(((txt[cnt]-'a')+(key[cnt%keyLen]+32-'a'))%MOD)+'a';
                else
                    out[cnt]=txt[cnt];
                break;
            default: out[cnt]=txt[cnt]; break;
        }
        cnt++;
    }
    return out;
}
char *decryptViginere(char *txt,char *key){
    int keyLen = strlen(key), txtLen = strlen(txt), cnt = 0;
    char *out = malloc(txtLen+1*sizeof(char));
    out[txtLen]='\0';
    while(cnt < txtLen){
        switch(isWhat(txt[cnt])){
            case 0:
                if(isUpperCase(key[cnt%keyLen])){
                    out[cnt]=(txt[cnt]-'A'-(key[cnt%keyLen]-'A'));
                    if(out[cnt]<0)
                        out[cnt]=(out[cnt]+MOD);
                    out[cnt]=(out[cnt]%MOD)+'A';
                }
                else
                    out[cnt]=txt[cnt];
                break;
            case 1:
                if(isUpperCase(key[cnt%keyLen])){
                    out[cnt]=(txt[cnt]-'a'-(key[cnt%keyLen]+32-'a'));
                    if(out[cnt]<0)
                        out[cnt]=(out[cnt]+MOD);
                    out[cnt]=(out[cnt]%MOD)+'a';
                }
                else
                    out[cnt]=txt[cnt];
                break;
            default: out[cnt]=txt[cnt]; break;
        }
        cnt++;
    }
    return out;
}
main(){
    char *txt = malloc(128*sizeof(char)), *key = malloc(128*sizeof(char)), *out=malloc(128*sizeof(char));
    char prompt = 0;
    loop:
        printf("Enter plain text:: ");	//txt lim = 127 chars
        scanf("%127[^\n]s",txt);
        while(getchar()!='\n');
        printf("Enter key:: ");
        scanf("%127[^\n]s",key);
        while(getchar()!='\n');
        normalizeKey(key);
        out = encryptViginere(txt,key);
        printf("Encrypted:: %s\n",out);
        txt = decryptViginere(out,key);
        printf("Decrypted:: %s\nContinue(Y/N)",txt);
        scanf("%c",&prompt);
        getchar();
        if(prompt == 'Y' || prompt == 'y')
            goto loop;
        return 0;
}