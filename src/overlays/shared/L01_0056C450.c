#include "common.h"

typedef int u128 __attribute__((mode(TI)));
extern s32 func_L01_0056C7E8();
extern s32 func_L01_0056DE68(u8 *arg0, s32 arg1);
extern void func_L01_0056E278(void *, void *, void *);
extern void func_L01_0056E4B0(void *, void *, void *);
extern s32 D_00222DA0;
extern s32 D_222C18;

// Builds a record from one of two tables for an object and passes it on.
s32 func_L01_0056C450(u8 *arg0, u8 *arg1, s32 arg2) {
    u128 buf;
    s32 a;
    s32 c;
    s32 b;
    s32 d;
    s32 off;
    if (arg0 == 0) return 0;
    if (arg1 == 0) return 0;
    if (arg2 == 0) return 0;
    if (*(s16 *)arg0 <= 0 && *(s32 *)(arg0 + 4) == -1) return 0;
    a = *(s32 *)(arg0 + 8);
    if (a != -1) {
        func_L01_0056E4B0(D_00222DA0 + (a << 7), &buf, func_L01_0056DE68(arg0, 1));
    } else if ((c = *(s32 *)(arg1 + 0x180)) != -1) {
        func_L01_0056E4B0(D_00222DA0 + (c << 7), &buf, func_L01_0056DE68(arg0, 1));
    } else if ((b = *(s32 *)(arg1 + 0x184)) != -1) {
        off = b * 0x30 + 0x20;
        func_L01_0056E278(D_222C18 + off, &buf, func_L01_0056DE68(arg0, 1));
    } else if ((d = *(s32 *)arg1) != -1) {
        off = d * 0x30 + 0x20;
        func_L01_0056E278(D_222C18 + off, &buf, func_L01_0056DE68(arg0, 1));
    } else {
        return 0;
    }
    return func_L01_0056C7E8(buf, arg0, arg1, arg2);
}
