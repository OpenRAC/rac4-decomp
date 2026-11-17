#include "common.h"

extern void *func_L00_007099F0(void);
void *D_00220A0C = 0;
void *D_00220A10 = 0;
void *D_00220A14 = 0;

/* Pops entries from the pending list, relinking those that match the owner and id into a new list. */
void func_L00_0070A010(s32 arg0, s32 arg1) {
    void *s0;
    void *s1;
    s32 done;
    void *a0;

    s0 = 0;
    s1 = 0;
    done = 0;
    do {
        a0 = func_L00_007099F0();
        if (a0 != 0) {
            if (*(s32 *)a0 != arg0 || (arg1 != -1 && arg1 != *(s32 *)((u8 *)a0 + 8))) {
                D_00220A0C = *(void **)((u8 *)D_00220A0C + 0x19C);
                *(void **)((u8 *)a0 + 0x19C) = 0;
                if (s0 != 0) {
                    *(void **)((u8 *)s0 + 0x19C) = a0;
                }
                s0 = a0;
                if (s1 == 0) {
                    s1 = s0;
                }
            }
        } else {
            done = 1;
        }
    } while (done == 0);
    D_00220A10 = s1;
    D_00220A14 = s0;
}
