#include "common.h"

extern s32 func_00157F98(void);
extern void func_00158A30(s32 id, s32 size, void *data);
extern s32 func_00159488(s32 arg0);

/* Flags checked by func_001591F0, defined in this file because they are reached through $gp. */
s32 D_0021DCB4 = 0;
s32 D_0021DCF0 = 0;

/* Waits for a flag to clear, then calls two routines and clears the first flag. */
void func_001591F0(void) {
    if (D_0021DCB4 != 0) {
        if (D_0021DCF0 != 0) {
            do {
            } while (func_00157F98() != 0);
        }
        func_00159488(0);
        func_00158A30(0x35, 0, 0);
        D_0021DCB4 = 0;
    }
}
