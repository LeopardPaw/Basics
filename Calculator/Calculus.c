#include <stdio.h>
#include "Fraction.h"
#include "Rounding.h"
void decimalRestorer(float *x,int cnt);
int decimalFixer(float *x,int cnt);
float power(int x, struct Fraction y);
float binomialSeries(float x,float k);
float logbase(float x, int base);

main()
{
    int x=0;
	printf("Enter a number:: ");
	scanf("%d",&x);
	printf("%.4f\n",logbase(x,10));
	printf("Continue:: (Y/N) ");
	scanf("%s",&x);
	if((x == 'y') || (x == 'Y'))
		return main();
	return 0;
}

float power(int x, struct Fraction k)
{
	reduce(&k);
	if(k.denominator==1)
	{
		int intPower(float x,int y);
		return intPower(x,k.numerator);
	}
	return decimalValue(k)*logbase(x,10);
}
int intPower(float x, int y)
{
	if(y==1)
		return x;
	if(y==0)
		return 1;
	return x*intPower(x,y-1);
}
countNumTens(float x) //Returns highest power needed to produce number, set to work only with POSITIVE powers eg 100 returns 2
{
	return floor(x) > 9 ? 1 + countNumTens(floor(x/10)) : 0;
}
float logbase(float x,int base)
{
	int countNumTens(float num);
}
void decimalRestorer(float *x,int cnt)
{
	if(cnt>40)
		cnt=40;
	while(cnt>0)
	{
		(*x)=(*x)/10;
		cnt--;
	}
}
decimalFixer(float *x,int cnt)
{
	if(cnt>=40)
		return cnt;
	if((float)((int)*x) == *x)
		return cnt;
	(*x)=(*x)*10;
	return decimalFixer(x,cnt+1);
}