/* cflags: -O2 -G8 -Wa,-G0 -Wuninitialized */
#include "common.h"
typedef unsigned long long u128;
extern int func_0054A7E0(int, int);
extern unsigned char *func_00548D28(int, int);
extern int func_0054A788(int, int, int);
extern void func_004742D8(void *, u128, int, int, float, float, float, int, int);

void func_L01_00412848(void *actor, u128 position, float scale) {
    char *data = *(char **)((char *)actor + 0xAC);
    int flags = 0x801;
    unsigned char count;
    int extra;
    if (func_0054A7E0(*(int *)(*(char **)(data + 0x40) + 0x26E4), 5) == 3)
        flags = 0x800801;
    if (func_0054A7E0(*(int *)(*(char **)(data + 0x40) + 0x26E4), 5) == 7)
        flags |= 0x80;
    if (func_0054A7E0(*(int *)(*(char **)(data + 0x40) + 0x26E4), 5) == 8)
        flags |= 0x40;
    if (func_0054A7E0(*(int *)(*(char **)(data + 0x40) + 0x26E4), 5) == 6)
        flags |= 0x100;
    if (func_0054A7E0(*(int *)(*(char **)(data + 0x40) + 0x26E4), 5) == 5)
        flags |= 0x400;
    count = func_00548D28(5, 0)[0x2F];
    extra = func_0054A788(*(int *)(*(char **)(data + 0x40) + 0x26E4), 5, 4);
    if (extra > 0) {
        flags |= 0x20;
        count += extra;
    }
    func_004742D8(actor, position, flags, 1, .3f, scale, (float)(extra + 1), count, 0);
}
