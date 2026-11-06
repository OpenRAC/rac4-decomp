#include "common.h"

s32 D_00220E4C = 0;
typedef struct Type1 {
    char data[0x18];
} Type1;
extern Type1 D_00354EA0[];
extern void func_00453718(void *, const void *, s32);

/* Append a fixed-size record to the shared queue. */
void func_00543398(const void *record)
{
    func_00453718(&D_00354EA0[D_00220E4C], record, 0x18);
    D_00220E4C++;
}
