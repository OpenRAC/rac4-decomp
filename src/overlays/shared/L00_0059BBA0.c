#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    void (*f8)(void *);
    s32 fc;
    s32 f10;
} Type2;

extern Type2 D_004EEE00[];

/* Calls the handler in D_004EEE00's entry for the halfword at offset 0x8C of arg0, if set. */
void func_L00_0059BBA0(void *arg0) {
    void (*temp)(void *);

    temp = D_004EEE00[*(s16 *)((u8 *)arg0 + 0x8C)].f8;
    if (temp != NULL) {
        temp(arg0);
    }
}
