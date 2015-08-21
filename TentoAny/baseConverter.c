#include <stdio.h>
#include <math.h>
#include <stdlib.h>

main(void)
{
	char *baseConverter(int x, int y);
	char *baseXtoTen(char *x,int base);
	char *ans,*num2;
	int base;
	unsigned int num=0;//num2=0;
	printf("Enter number:: ");
	scanf("%d",&num);
	printf("Enter base:: ");
	scanf("%d",&base);
	ans=baseConverter(num,base);
	printf("%s",ans);
	//num2=baseXtoTen(ans,base);
	//printf(" num == %d num2 == %s",num,num2);
	printf("\nContinue?:: ");
	scanf("%s",&num);
	if((num=='y')||(num=='Y'))
		return main();
	return 0;
}
enum values{zero='0',one='1',two='2',three='3',four='4',five='5',six='6',seven='7',eight='8',nine='9',A='A',B='B',
			C='C',D='D',E='E',F='F',G='G',H='H',I='I',J='J',K='K',L='L',M='M',N='N',O='O',P='P',Q='Q',R='R',S='S',
			T='T',U='U',V='V',W='W',X='X',Y='Y',Z='Z',a='a',b='b',c='c',d='d',e='e',f='f',g='g',h='h',i='i',j='j',
			k='k',l='l',m='m',n='n',o='o',p='p',q='q',r='r',s='s',t='t',u='u',v='v',w='w',x='x',y='y',z='z',a1='+'
			,a2='/'};
char *baseConverter(int num,int base)
{
	unsigned int size,pos;
	char *ans=(char *)malloc(sizeof(char));
	if(base<33)
	{
		char *baseConverter1(int num1,int base1);
		if(base<2)
		{
			char *ans=(char *)malloc(sizeof(char));
			printf("Radix to small.");
			ans[0]='\0';
			return ans;
		}
		free(ans);
		return baseConverter1(num,base);
	}
	size=(int)(log((float)num)/log((float)base))+2;
	ans=(char *)realloc(ans,sizeof(char)*size);
	pos=size-1;
	ans[pos--]='\0';
	while(num>0)
	{
		size=num%base;
		switch(size)
		{
			case(0): ans[pos--]=A; break;
			case(1): ans[pos--]=B; break;
			case(2): ans[pos--]=C; break;
			case(3): ans[pos--]=D; break;
			case(4): ans[pos--]=E; break;
			case(5): ans[pos--]=F; break;
			case(6): ans[pos--]=G; break;
			case(7): ans[pos--]=H; break;
			case(8): ans[pos--]=I; break;
			case(9): ans[pos--]=J; break;
			case(10): ans[pos--]=K; break;
			case(11): ans[pos--]=L; break;
			case(12): ans[pos--]=M; break;
			case(13): ans[pos--]=N; break;
			case(14): ans[pos--]=O; break;
			case(15): ans[pos--]=P; break;
			case(16): ans[pos--]=Q; break;
			case(17): ans[pos--]=R; break;
			case(18): ans[pos--]=S; break;
			case(19): ans[pos--]=T; break;
			case(20): ans[pos--]=U; break;
			case(21): ans[pos--]=V; break;
			case(22): ans[pos--]=W; break;
			case(23): ans[pos--]=X; break;
			case(24): ans[pos--]=Y; break;
			case(25): ans[pos--]=Z; break;
			case(26): ans[pos--]=a; break;
			case(27): ans[pos--]=b; break;
			case(28): ans[pos--]=c; break;
			case(29): ans[pos--]=d; break;
			case(30): ans[pos--]=e; break;
			case(31): ans[pos--]=f; break;
			case(32): ans[pos--]=g; break;
			case(33): ans[pos--]=h; break;
			case(34): ans[pos--]=i; break;
			case(35): ans[pos--]=j; break;
			case(36): ans[pos--]=k; break;
			case(37): ans[pos--]=l; break;
			case(38): ans[pos--]=m; break;
			case(39): ans[pos--]=n; break;
			case(40): ans[pos--]=o; break;
			case(41): ans[pos--]=p; break;
			case(42): ans[pos--]=q; break;
			case(43): ans[pos--]=r; break;
			case(44): ans[pos--]=s; break;
			case(45): ans[pos--]=t; break;
			case(46): ans[pos--]=u; break;
			case(47): ans[pos--]=v; break;
			case(48): ans[pos--]=w; break;
			case(49): ans[pos--]=x; break;
			case(50): ans[pos--]=y; break;
			case(51): ans[pos--]=z; break;
			case(52): ans[pos--]=zero; break;
			case(53): ans[pos--]=one; break;
			case(54): ans[pos--]=two; break;
			case(55): ans[pos--]=three; break;
			case(56): ans[pos--]=four; break;
			case(57): ans[pos--]=five; break;
			case(58): ans[pos--]=six; break;
			case(59): ans[pos--]=seven; break;
			case(60): ans[pos--]=eight; break;
			case(61): ans[pos--]=nine; break;
			case(62): ans[pos--]=a1; break;
			case(63): ans[pos--]=a2; break;
		}
		num=(int)(num/base);
	}
	return ans;
}
//Converts base 10 to any base less than 33
//uses base32hex for base 32
char *baseConverter1(int num,int base)
{
	unsigned int size=(int)(log((float)num)/log((float)base))+2;
	char *ans=(char *)calloc(size+2,sizeof(char));
	unsigned int pos=size-1;
	ans[pos--]='\0';
	while(num>0)
	{
		size=num%base;
		switch(size)
		{
			case(0): ans[pos--]=zero; break;
			case(1): ans[pos--]=one; break;
			case(2): ans[pos--]=two; break;
			case(3): ans[pos--]=three; break;
			case(4): ans[pos--]=four; break;
			case(5): ans[pos--]=five; break;
			case(6): ans[pos--]=six; break;
			case(7): ans[pos--]=seven; break;
			case(8): ans[pos--]=eight; break;
			case(9): ans[pos--]=nine; break;
			case(10): ans[pos--]=A; break;
			case(11): ans[pos--]=B; break;
			case(12): ans[pos--]=C; break;
			case(13): ans[pos--]=D; break;
			case(14): ans[pos--]=E; break;
			case(15): ans[pos--]=F; break;
			case(16): ans[pos--]=G; break;
			case(17): ans[pos--]=H; break;
			case(18): ans[pos--]=I; break;
			case(19): ans[pos--]=J; break;
			case(20): ans[pos--]=K; break;
			case(21): ans[pos--]=L; break;
			case(22): ans[pos--]=M; break;
			case(23): ans[pos--]=N; break;
			case(24): ans[pos--]=O; break;
			case(25): ans[pos--]=P; break;
			case(26): ans[pos--]=Q; break;
			case(27): ans[pos--]=R; break;
			case(28): ans[pos--]=S; break;
			case(29): ans[pos--]=T; break;
			case(30): ans[pos--]=U; break;
			case(31): ans[pos--]=V; break;
		}
		num=(int)(num/base);
	}
	return ans;
}
char* baseXtoTen(char *num,int base)
{
	unsigned int pos=0,size=0,finalAnswer=0;
	char *ans=(char *)malloc(sizeof(char));
	if(base<33)
	{
		while(num[pos]!=NULL)
		{
			switch(num[pos])
			{
				case(zero): ans[pos]=0; break;
				case(one): ans[pos]=1; break;
				case(two): ans[pos]=2; break;
				case(three): ans[pos]=3; break;
				case(four): ans[pos]=4; break;
				case(five): ans[pos]=5; break;
				case(six): ans[pos]=6; break;
				case(seven): ans[pos]=7; break;
				case(eight): ans[pos]=8; break;
				case(nine): ans[pos]=9; break;
				case(A): ans[pos]=10; break;
				case(B): ans[pos]=11; break;
				case(C): ans[pos]=12; break;
				case(D): ans[pos]=13; break;
				case(E): ans[pos]=14; break;
				case(F): ans[pos]=15; break;
				case(G): ans[pos]=16; break;
				case(H): ans[pos]=17; break;
				case(I): ans[pos]=18; break;
				case(J): ans[pos]=19; break;
				case(K): ans[pos]=20; break;
				case(L): ans[pos]=21; break;
				case(M): ans[pos]=22; break;
				case(N): ans[pos]=23; break;
				case(O): ans[pos]=24; break;
				case(P): ans[pos]=25; break;
				case(Q): ans[pos]=26; break;
				case(R): ans[pos]=27; break;
				case(S): ans[pos]=28; break;
				case(T): ans[pos]=29; break;
				case(U): ans[pos]=30; break;
				case(V): ans[pos]=31; break;
			}
			ans=(char *)realloc(ans,++pos);
		}
	}
	else
	{
		while(num[pos]!=NULL)
		{
			switch(num[pos])
			{
				case(A): ans[pos]=0; break;
				case(B): ans[pos]=1; break;
				case(C): ans[pos]=2; break;
				case(D): ans[pos]=3; break;
				case(E): ans[pos]=4; break;
				case(F): ans[pos]=5; break;
				case(G): ans[pos]=6; break;
				case(H): ans[pos]=7; break;
				case(I): ans[pos]=8; break;
				case(J): ans[pos]=9; break;
				case(K): ans[pos]=10; break;
				case(L): ans[pos]=11; break;
				case(M): ans[pos]=12; break;
				case(N): ans[pos]=13; break;
				case(O): ans[pos]=14; break;
				case(P): ans[pos]=15; break;
				case(Q): ans[pos]=16; break;
				case(R): ans[pos]=17; break;
				case(S): ans[pos]=18; break;
				case(T): ans[pos]=19; break;
				case(U): ans[pos]=20; break;
				case(V): ans[pos]=21; break;
				case(W): ans[pos]=22; break;
				case(X): ans[pos]=23; break;
				case(Y): ans[pos]=24; break;
				case(Z): ans[pos]=25; break;
				case(a): ans[pos]=26; break;
				case(b): ans[pos]=27; break;
				case(c): ans[pos]=28; break;
				case(d): ans[pos]=29; break;
				case(e): ans[pos]=30; break;
				case(f): ans[pos]=31; break;
				case(g): ans[pos]=32; break;
				case(h): ans[pos]=33; break;
				case(i): ans[pos]=34; break;
				case(j): ans[pos]=35; break;
				case(k): ans[pos]=36; break;
				case(l): ans[pos]=37; break;
				case(m): ans[pos]=38; break;
				case(n): ans[pos]=39; break;
				case(o): ans[pos]=40; break;
				case(p): ans[pos]=41; break;
				case(q): ans[pos]=42; break;
				case(r): ans[pos]=43; break;
				case(s): ans[pos]=44; break;
				case(t): ans[pos]=45; break;
				case(u): ans[pos]=46; break;
				case(v): ans[pos]=47; break;
				case(w): ans[pos]=48; break;
				case(x): ans[pos]=49; break;
				case(y): ans[pos]=50; break;
				case(z): ans[pos]=51; break;
				case(zero): ans[pos]=52; break;
				case(one): ans[pos]=53; break;
				case(two): ans[pos]=54; break;
				case(three): ans[pos]=55; break;
				case(four): ans[pos]=56; break;
				case(five): ans[pos]=57; break;
				case(six): ans[pos]=58; break;
				case(seven): ans[pos]=59; break;
				case(eight): ans[pos]=60; break;
				case(nine): ans[pos]=61; break;
				case(a1): ans[pos]=62; break;
				case(a2): ans[pos]=63; break;
			}
			ans=(char *)realloc(ans,++pos);
		}
	}
	ans[pos]='\0';
	return ans;
}