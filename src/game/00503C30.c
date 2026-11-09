#include "common.h"

extern void func_0015DB88(s32 *);
extern void *func_005010E0(void);
extern void *func_005011A8(void *, s32);
extern s32 D_00222038[];

void func_00503C30(s32 *arg0, s32 arg1) {
    s32 i;
    s32 *cur;
    u8 *object;
    u8 *entry;

    if (arg0 != 0) {
        i = 0;
        if (*arg0 != 0) {
        cur = arg0;
        do {
            if (D_00222038[1] != 0) {
                object = (u8 *)D_00222038;
            } else {
                object = func_005010E0();
            }
            entry = func_005011A8(object, 2);
            i++;
            (*(void (**)(void *, s32))(*(u8 **)entry + 0xC))(entry, *cur);
            *cur = 0;
            cur++;
        } while (i < 0x30 && *cur != 0);
        }
    }
    if (arg1 & 1) func_0015DB88(arg0);
}
