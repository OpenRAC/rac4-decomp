/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern u32 func_01EED8A4(s32, s32, s32);
extern s32 func_01EEE39C(void);
extern void func_01F0C090(const char *, s32);
extern void func_01EE68FC(void *, s8 *, s32);
extern s32 func_01EF4188(void *, s32, s32, s32, void *);
extern char D_0019C9F0[];
extern char D_0019CA00[];

typedef s32 (*VtFn)(void *);
typedef void (*VtFnArgs)(void *, s32, void *);

/* Checks obj's state, then dispatches the request in arg1 through its vtable. */
s32 func_01EF5C54(u8 *obj, u8 *arg1)
{
    s32 temp_s1;
    s32 temp_s2;
    s8 *temp_a1;
    void **temp_v0;
    void **temp_v0_2;
    void **vt;

    temp_s1 = *(s32 *)(*(u8 **)(obj + 0x80) + 4);
    if (*(s32 *)obj == 0) {
        func_01F0C090(D_0019C9F0, 0xA2);
    }
    if (temp_s1 == 0) {
        func_01F0C090(D_0019C9F0, 0xA3);
    }
    if (arg1 == NULL) {
        func_01F0C090(D_0019C9F0, 0xA4);
    }
    vt = *(void ***)(obj + 0xB0);
    if (((VtFn)(vt[8]))(obj) != 0) {
        if (func_01EED8A4(temp_s1, 0x11, 0x10) != 0) {
            vt = *(void ***)(obj + 0xB0);
            if (((VtFn)(vt[9]))(obj) == 0) {
                if (*(s32 *)(arg1 + 0x5B10) == 0) {
                    temp_a1 = *(s8 **)(obj + 0xC0);
                    if ((temp_a1 != NULL) && (*temp_a1 != 0)) {
                        func_01EE68FC(arg1, temp_a1, *(s32 *)(obj + 0xC8));
                        temp_v0 = (void **)func_01EEE39C();
                        ((VtFnArgs)((*(void ***)temp_v0)[3]))(temp_v0, 1, D_0019CA00);
                        return 0;
                    }
                }
                temp_v0_2 = (void **)func_01EEE39C();
                ((VtFnArgs)((*(void ***)temp_v0_2)[3]))(temp_v0_2, 6, D_0019CA00);
            }
        }
        if ((func_01EED8A4(temp_s1, 0x11, 0) != 0) || (func_01EED8A4(temp_s1, 0x11, 1) != 0) || (func_01EED8A4(temp_s1, 0x11, 2) != 0) || (func_01EED8A4(temp_s1, 0x11, 3) != 0)) {
            temp_s2 = *(s32 *)(*(u8 **)(obj + 0x80));
            if (temp_s2 == 0) {
                func_01F0C090(D_0019C9F0, 0xCE);
            }
            return func_01EF4188(obj, temp_s1, temp_s2, *(s32 *)obj, arg1) == 0;
        }
        return 1;
    }
    return 1;
}
