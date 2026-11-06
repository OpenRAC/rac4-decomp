/* cflags: -O2 -G8 -Wa,-G0 -Wuninitialized */
#include "common.h"
typedef unsigned long long u128;
extern int func_0054BD48(int, int);
extern unsigned char *func_0054A290(int, int);
extern int func_0054BCF0(int, int, int);
extern void func_00474BB0(void *, u128, int, int, float, float, float, int, int);
/* Build effect flags and adjusted byte count from the actor's weapon data. */
void func_L01_004133F0(void *actor, u128 position, float scale) {
    char *data = *(char **)((char *)actor + 0xAC);
    int flags = 0x801;
    unsigned char count;
    int extra;
    if (func_0054BD48(*(int *)(*(char **)(data + 0x40) + 0x26E4), 5) == 3)
        flags = 0x800801;
    if (func_0054BD48(*(int *)(*(char **)(data + 0x40) + 0x26E4), 5) == 7)
        flags |= 0x80;
    if (func_0054BD48(*(int *)(*(char **)(data + 0x40) + 0x26E4), 5) == 8)
        flags |= 0x40;
    if (func_0054BD48(*(int *)(*(char **)(data + 0x40) + 0x26E4), 5) == 6)
        flags |= 0x100;
    if (func_0054BD48(*(int *)(*(char **)(data + 0x40) + 0x26E4), 5) == 5)
        flags |= 0x400;
    count = func_0054A290(5, 0)[0x2F];
    extra = func_0054BCF0(*(int *)(*(char **)(data + 0x40) + 0x26E4), 5, 4);
    if (extra > 0) {
        flags |= 0x20;
        count += extra;
    }
    func_00474BB0(actor, position, flags, 1, .3f, scale, (float)(extra + 1), count, 0);
}
