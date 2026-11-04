#include "common.h"

extern s32 D_002F3CD0[];
extern void func_00163990(void);
extern s32 func_004A3AF0(s32, s32, s32);

s32 D_0021F690 = 0;

/* Advance the ring and periodically flush pending work. */
void func_0049A410(s32 arg0, s32 arg1)
{
    s32 node;
    s32 child;
    s32 index;
    s32 next;
    if (arg1 == 1) {
        D_0021F690++;
        if (D_0021F690 >= 6) {
            D_0021F690 = 0;
            func_00163990();
        }
        return;
    }
    if (arg1 == 0) {
        node = *(s32 *)((s32)D_002F3CD0 + D_002F3CD0[0] * 4 + 0xC);
        child = *(s32 *)node;
        if (child != 0) {
            func_004A3AF0(*(s32 *)(node + 4), *(s32 *)(child + 4), 0);
        }
    }
    index = D_002F3CD0[0];
    *(volatile s32 *)&D_0021F690 = 0;
    next = index + 1;
    next %= 8;
    D_002F3CD0[2]--;
    D_002F3CD0[0] = next;
}
