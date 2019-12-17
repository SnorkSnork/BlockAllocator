#include <stdio.h>


//defining block size and ammount of them
#define BS 100 // size of one block
#define BA 100 // ammount of blocks

//creating structure of one block
typedef struct block_t
{
    char data[BS];
} block_t;

//Allocator itself
typedef struct Allocator{
    block_t Blocks[BA];
    block_t* Stack[BA];
    int sp;
} allocator;




    int init(allocator *A){
        A->sp = 0;
        int i;
        for (i = 0; i<BA; ++i){
            A->Stack[i] = &(A->Blocks[i]);
            ++(A->sp);
        }
        return 0;//To check that we have enough space in memory for such ammount of blocks of such size
    }   //if result of this function is not 0, something gone wrong, allocator initiation is not sucsessful

    block_t *newBlock(allocator *A){
        if (A->sp){
            --(A->sp);
            int i;
            for (i=0; i<BS; ++i)
                ((*A).Stack[A->sp])->data[i] = 0;
            return (A->Stack[A->sp]);
        }
        else {
            fprintf (stderr, "ERROR!\tNo any more blocks avaliable\n");
            return NULL;
        }
    }

    void delBlock (allocator *A, block_t *bl_n){
        A->Stack[(A->sp)++] = bl_n;
    }

    int state(allocator A){
        return (A.sp);
    }


