#include "common.h"

extern void func_0047F568(s32, s32, s32, s32, s32);
extern s32 D_0021DDB4;
extern s32 D_0021EDC4;
extern s32 D_239660[];
extern void func_0045C610(void);

/* Stores two words and a callback into D_239660, then starts the func_0047F568 sequence when both globals say so. */
void func_0045C598(s32 arg0, s32 arg1, void *arg2) {
    u8 *p = (u8 *)D_239660;

    *(s32 *)(p + 0x98) = arg0;
    *(s32 *)(p + 0x9C) = arg1;
    if (arg2 != NULL) {
        *(void **)(p + 0xA0) = arg2;
    } else {
        *(void **)(p + 0xA0) = (void *)func_0045C610;
    }
    if (D_0021DDB4 == 0 && D_0021EDC4 == -2) {
        func_0047F568(4, 1, 0x10, 0, 0);
    }
}
