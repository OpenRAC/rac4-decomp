#include "common.h"

extern s32 func_L00_005BC9B8(void *);
extern void func_L00_005F6C28(void *, int, int);
extern void func_L01_004B6D28(void *);
extern void func_L01_004B6F50(void *);

/* Handles messages 0 and 3 (reset and notify the sub-object), and message 2 when the halfword at 0x5E6 is not positive. */
s32 func_L01_004B8CF8(void *arg0, s32 arg1) {
    unsigned char *state = *(unsigned char **)((char *)arg0 + 0xAC);

    switch (arg1) {
    case 0:
    case 3:
        func_L01_004B6D28(arg0);
        func_L00_005BC9B8(state + 0x5E6);
        break;
    case 2:
        if (*(s16 *)(state + 0x5E6) <= 0) {
            func_L00_005F6C28(arg0, 5, 0);
            func_L01_004B6F50(arg0);
        }
        break;
    }
    return 1;
}
