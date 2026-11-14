#include "common.h"

extern void func_L00_0076DED0(s32 arg0, s32 arg1, s32 arg2);

/* Looks up the entry at index arg1 in the table at arg0, stores the index in arg2 when the entry tag matches, and returns the entry or NULL. */
void *func_L00_0076D220(void *arg0, s32 arg1, s32 *arg2) {
    s32 idx;
    s32 gen;
    void *r;

    func_L00_0076DED0(arg1, (s32)&idx, (s32)&gen);
    r = 0;
    if (idx < *(s32 *)arg0) {
        r = (void *)((u8 *)*(s32 *)((u8 *)arg0 + 4) + idx * 0xD8);
    }
    if (r != 0) {
        if (gen == (s32)(*(u32 *)((u8 *)r + 4) >> 12)) {
            if (arg2 != 0) {
                *arg2 = idx;
            }
        }
    }
    return r;
}
