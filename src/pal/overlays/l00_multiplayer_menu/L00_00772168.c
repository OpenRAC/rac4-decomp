#include "common.h"

typedef struct Type2 {
    u8 p0[4];
    u32 f4;
    u8 p8[0xD4 - 8];
    struct Type2 *fD4;
} Type2;

typedef struct Type1 {
    u8 p0[8];
    Type2 *f8;
    u32 fC;
} Type1;

/* Pop one free node and stamp its high handle bits, skipping all ones. */
Type2 *func_L00_00772168(Type1 *arg0)
{
    Type2 *node = arg0->f8;
    u32 stamp;
    if (node != NULL) {
        arg0->f8 = node->fD4;
        node->fD4 = NULL;
        stamp = arg0->fC++;
        node->f4 = (node->f4 & 0xFFF) | (stamp << 12);
        if (node->f4 == 0xFFFFFFFF) {
            u32 stamp2 = arg0->fC++;
            node->f4 = (node->f4 & 0xFFF) | (stamp2 << 12);
        }
    }
    return node;
}
