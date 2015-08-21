#include <stdio.h>
#define nextFib(a,b) a+b
#define prevFib(a,b) b-a //b>=a
main()
{
	int limit = 3;
	int sumMultiples_3_OR_5_BelowX(int x);
	int sumEvenFibonacciBelowX(int x);
	int diffBetweenSumSquaresAndSquareSums(int x);
	unsigned long long sumSelfPowers(int x);
	int option = 0;
	while(1)
	{
		printf("Enter program number or -1 for program list:: ");
		scanf("%d",&option);
		switch (option)
		{
			case(-1): printf("DO THIS LATER\n"); break;
			case(0): printf("Enter limit:: "); scanf("%d", &limit); printf("Sum of all multiples of 3 or 5 below %d = %d\n", limit, sumMultiples_3_OR_5_BelowX(limit)); break;
			case(1): printf("Enter limit:: "); scanf("%d", &limit); printf("Sum even fibonacci numbers below %d = %d\n", limit, sumEvenFibonacciBelowX(limit)); break;
			case(2): break;
			case(3): break;
			case(4): break;
			case(5): printf("Enter limit:: "); scanf("%d", &limit); printf("Difference between sum of squares and square of sums of 1 to %d = %d\n",limit,diffBetweenSumSquaresAndSquareSums(limit));break;
			case(6): break;
			case(7): break;
			case(8): break;
			case(9): break;
			case(10): break;
			case(11): break;
			case(12): break;
			case(13): break;
			case(14): break;
			case(15): break;
			case(16): break;
			case(17): break;
			case(18): break;
			case(19): break;
			case(20): break;
			case(21): break;
			case(22): break;
			case(23): break;
			case(24): break;
			case(25): break;
			case(26): break;
			case(27): break;
			case(28): break;
			case(29): break;
			case(30): break;
			case(31): break;
			case(32): break;
			case(33): break;
			case(34): break;
			case(35): break;
			case(36): break;
			case(37): break;
			case(38): break;
			case(39): break;
			case(40): break;
			case(41): break;
			case(42): break;
			case(43): break;
			case(44): break;
			case(45): break;
			case(46): break;
			case(47): printf("Enter limit:: "); scanf("%d", &limit); printf("Last ten digits of the sum of self powers from 1 to %d = %llu\n",limit,sumSelfPowers(limit)); break;
			default: printf("%d is invalid.\n", option); break;
		}
		printf("Continue(Y/N):: ");
		scanf("%s",&option);
		if(option!='Y'&&option!='y')
			return 0;
	}
}
sumMultiples_3_OR_5_BelowX(int x)
{
	int s = 0;
	while(--x>2)
	{
		if(x%3==0 || x%5==0)
			s+=x;
	}
	return s;
}
sumEvenFibonacciBelowX(int x)
{
	int a = 1, b = 1,s = 0;
	while (b <= x)
	{
		if(b%2==0)
			s+=b;
		b = nextFib(a,b);
		a = prevFib(a,b);
	}
	return s;
}
unsigned long long sumSelfPowers(int x)
{
	unsigned long long power(int x,int y);
	unsigned long long lastTen = 0;
	while(x>0)
	{
		lastTen +=power(x,x);
		x--;
	}
	return lastTen%10000000000;
}
unsigned long long power(int x, int y) //mod 10E10,possibly...
{
	return (y<=0)?1:(x*power(x,--y))%10000000000;
}
sumSquaresFrom1ToX(int x)
{
	#define square(x) x*x
	int s = 0;
	while(x>0)
		s+=square(x); x--;
}
sumNumbersFrom1ToX(int x)
{
	int s = 0;
	while(x>0)
		s+=x; x--;
}
diffBetweenSumSquaresAndSquareSums(int x)
{
	#define square(x) x*x
	int sumSquaresFrom1ToX(int x);
	int sumNumbersFrom1ToX(int x);
	return square(sumNumbersFrom1ToX(x))-sumSquaresFrom1ToX(x);
}