#include <stdio.h>
#include <stdlib.h>
#define MAX_LOOP_EXIT 64 //after this many attempts, program executes main_loop
//char *baseXtoY
main(){
	int base_x,base_y,choice=-1,loopTracker=0;
    main_loop: //im well aware that goto statements arent the best idea. they work for this though
    loopTracker=0;
    printf("Press 0 for help or enter a radix:: ");
    scanf("%d",&choice);
    if(choice==0)
        printf("This is a base conversion tool\nBases 2 to 36 are supported\n");
    else{
        base_x = choice;
        b_x_loop:
        if(loopTracker == MAX_LOOP_EXIT)
            goto main_loop;
        if(base_x>36||base_x<2){
            loopTracker++;
            printf("ERROR %d is unsupported\n",base_x);
            printf("Please choose a radix between 2 and 36");
            scanf("%d",&base_x);
            goto b_x_loop;
        }
        
	return 0;
}