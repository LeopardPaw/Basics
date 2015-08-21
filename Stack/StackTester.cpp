#include "Stack.h"
int main()
{
	int x=10;
	stackT *stack1=&(stackInit(&x));
	stackAdd(stack1,&x);
	printf("Output:: %d",(int *)stackPoll(stack1));
}