

#include "Stack.h"


int CheckPop(int *in, int *out, int insize, int outsize)
{
    Stack stack;
    int ii = 0;
    int oi = 0;
    assert(in != NULL);
    assert(out != NULL);
    if(insize != outsize) {
        return 0;
    }
    while() {
        if (in[ii] != out[oi]) {
            if(!Stack_Empty(&stack) && Stack_Top(&stack) != out[oi]) {
                Stack_Push(&stack, in[ii]);
                ii++;
            }
            else {

            }
        }
    }

   return 0;
}


void CheckPopTest()
{
    int push[] = {1, 2, 3, 4, 5};
    int pop[] = {1, 2, 3, 4, 5};
    int pushsize = sizeof(push) / sizeof(push[0]); 
    int popsize = sizeof(pop) / sizeof(pop[0]); 
    CheckPop(push, pop, pushsize, popsize);
}
