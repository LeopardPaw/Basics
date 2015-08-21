#include <stdio.h>
#include <stdlib.h>

main()
{
	void generateAnswers(FILE *inputFile, unsigned int **answers);
	char *path = (char *)calloc(512, sizeof(char));
	int x = 0;
	unsigned int *answers[15];
	for(;x<15;x++)
		answers[x]=(unsigned int *)calloc(99,sizeof(int));
	printf("Enter file path:: ");
	//scanf("%s",path);
	FILE *inputFile = fopen("input.txt","r");
	if (!inputFile) {
		perror("The following error occured:: ");
		goto finalLine;
	}
	generateAnswers(inputFile, answers);
	printf("Base 2:: %s\nBase 3:: %s\n Base 4:: %s\nBase 5:: %s\n",answers[0],answers[1],answers[2],answers[3]);
	printf("Base 6:: %s\nBase 7:: %s\n Base 8:: %s\nBase 9:: %s\n", answers[4], answers[5], answers[6], answers[7]);
	printf("Base 10:: %s\nBase 11:: %s\n Base 12:: %s\nBase 13:: %s\n", answers[8], answers[9], answers[10],answers[11]);
	printf("Base 14:: %s\nBase 15:: %s\n Base 16:: %s\n", answers[12], answers[13], answers[14]);
	finalLine:
		printf("DONE");
		scanf("%s",&x);
}
void generateAnswers(FILE *inputFile, unsigned int **answers)
{
	unsigned int *outMsg(unsigned int **orgMsg, int radix, int sz);
	unsigned int **orgMsg;
	int sz;
	int cnt;
	short radix = 2;
	fscanf(inputFile,"%d",&sz);
	orgMsg = (unsigned int **)calloc(sz+1,sizeof(int));
	cnt = sz;
	while(cnt-- > 0)
		fscanf(inputFile,"%s",*orgMsg++);
	fclose(inputFile);
	cnt = 0;
	while(cnt<15)
		answers[cnt++] = outMsg(orgMsg,radix++,sz);
}
unsigned power(int x, int y) //very lazy power function
{
	return (y<1)?1:(y==1)?x:power(x,y--);
}
unsigned int radixToTen(unsigned int *num, int radix)
{
	unsigned power(int x, int y);
	unsigned highestPower = 0;
	int *temp = num;
	while(temp != NULL)
	{
		temp++;
		highestPower++;
	}
	highestPower = power(highestPower, radix);
	unsigned ans = highestPower*(*num); //this could break very easily
	while (num != NULL)
	{
		num++;
		ans+=(highestPower/radix)*(*num);
	}
	return ans;
}
unsigned int *outMsg(unsigned int **orgMsg, int radix, int sz)
{
	/*----->Assumes full use of UNICODE is allowed
	*MAX digits in num necessary in base 2:: 32 -->MIN digits to get non control character in base 2:: 6
	*MAX digits in num necessary in base 3:: 21 -->MIN digits to get non control character in base 3:: 4
	*MAX digits in num necessary in base 4:: 16 -->MIN digits to get non control character in base 4:: 3
	*MAX digits in num necessary in base 5:: 14 -->MIN digits to get non control character in base 5:: 3
	*MAX digits in num necessary in base 6:: 13 -->MIN digits to get non control character in base 6:: 2
	*MAX digits in num necessary in base 7:: 12 -->MIN digits to get non control character in base 7:: 2
	*MAX digits in num necessary in base 8:: 11 -->MIN digits to get non control character in base 8:: 2
	*MAX digits in num necessary in base 9:: 11 -->MIN digits to get non control character in base 9:: 2
	*MAX digits in num necessary in base 10:: 10 -->MIN digits to get non control character in base 10:: 2
	*MAX digits in num necessary in base 11:: 10 -->MIN digits to get non control character in base 11:: 2
	*MAX digits in num necessary in base 12:: 9 -->MIN digits to get non control character in base 12:: 2
	*MAX digits in num necessary in base 13:: 9 -->MIN digits to get non control character in base 13:: 2
	*MAX digits in num necessary in base 14:: 9 -->MIN digits to get non control character in base 14:: 2
	*MAX digits in num necessary in base 15:: 9 -->MIN digits to get non control character in base 15:: 2
	*MAX digits in num necessary in base 16:: 8 -->MIN digits to get non control character in base 16:: 2
	*<----------Maybe later the other control characters could be counted out too
	*<----------If you need more than the above you are either
	*<----------using a different standard, or you have a problem...
	*<----------Or I do, but that's irrelevant, it should be fixed
	*/
	unsigned int *output = (unsigned int *)calloc(sz,sizeof(int));
	int x = 0;
	for(;x<sz;x++)
		output[x] = radixToTen(orgMsg[x],radix);
	return output;
}