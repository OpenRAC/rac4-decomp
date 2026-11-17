/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

extern s32 func_0011D920(s8 *, s8 *, ...);
extern void func_004B1080(s32 **, s32 **);
extern u8 D_0021F0F0[];
extern u8 D_00310290[];

/* Update the selected entry and its formatted value when it changes. */
void func_L41_0055EFB0(s32 index, f32 value) {
    s32 *first;
    s32 *second;
    s32 offset;
    s32 integer;
    u8 *entry;

    func_004B1080(&first, &second);
    if (*first == index) {
        index = 0;
    } else if (*second == index) {
        index = 1;
    }
    offset = index * 0x34;
    integer = (s32)value;
    entry = offset + D_00310290;
    if (integer != *(s32 *)entry) {
        *(s32 *)entry = integer;
        if (integer == 0) {
            entry[0x10] = 0;
            return;
        }
        func_0011D920((s8 *)(offset + D_00310290 + 0x10), (s8 *)D_0021F0F0, integer);
    }
}
