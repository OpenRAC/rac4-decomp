/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_01ED2458();
extern s32 func_01EAB270(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
u16 *func_01ED0BE0(void *, u8);
void func_01ED3B08(s32, void *, u16, u32);

// Finds or claims a slot for the entry in arg3 in the table of arg0 and records it; 8 on success, -1 with no object.
s32 func_01ED1B28(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3) {
    u8 *obj;
    u16 *row;
    u8 *slot;
    u8 *temp_a1;
    u16 temp_a2;
    u32 none;
    u32 bound;
    u32 idx;
    u32 i;

    obj = func_01ED2458();
    if (obj == NULL) {
        return -1;
    }
    if (*(s32 *)(arg3 + 4) == *(s32 *)(arg0 + 0x404)) {
        *(s32 *)(obj + 0x7C) = 1;
        ((s32 (*)(void *))func_01EAB270)(obj + 0x80);
        return 8;
    }
    row = func_01ED0BE0(arg0, *(u8 *)(arg3 + 2));
    if (row != NULL) {
        idx = *(u32 *)(obj + 0x14);
        none = idx;
        i = 0;
        bound = idx;
        for (; i < bound; i++) {
            if (*(u16 *)arg3 == row[i]) {
                idx = none;
                break;
            }
            if (*(u16 *)arg3 == *(u16 *)(*(u8 **)(obj + 0x90) + i * 12 + 8)) {
                idx = i;
                break;
            }
            if (idx == none && row[i] == 0xFFFE) {
                idx = i;
            }
        }
        if (idx != none) {
            temp_a1 = *(u8 **)(obj + 0x90);
            temp_a2 = *(u16 *)arg3;
            slot = (u8 *)(((idx * 3) << 2) + (u32)temp_a1);
            row[idx] = temp_a2;
            *(s16 *)(slot + 8) = -2;
            func_01ED3B08(*(s32 *)(slot + 4), temp_a1, temp_a2, i);
        }
    }
    return 8;
}
