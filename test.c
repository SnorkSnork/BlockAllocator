#include "allocator.h"

int main(){
    allocator Test;
    printf ("Let's begin!\n\n");
    init(&Test);
    printf ("Initiation is sucsessful!\n\nNow we'll allocate new block.\nAvaliable blocks before: %d\n", state(Test));
    block_t *test1 = newBlock(&Test);
    printf ("Now %d more blocks are avaliable for allocation\n", state(Test));//some test info
    delBlock (&Test, test1);
    printf ("And after deleting we have %d blocks for allocation\n", state(Test));
    printf ("\nIf we'll try to alocate more blocks than avaliable, we'd get next message:\n");
    int i;
    block_t *tests[BA+1];
    for (i=0; i<BA+1; ++i){
        tests[i] = newBlock(&Test);
    }
    printf ("Adress of extra block is %d\n", tests[BA+1]);
    printf ("\nTesting is finished sucsessfuly!\n");
}
