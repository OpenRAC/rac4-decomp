#include "common.h"

extern void *func_00453EB0(s16);
extern void func_0048A950(void *arg0);
extern void *func_0048A970(u32 arg0);

/* Looks up the entry for arg1; when arg0 is nonzero, stores it in the slot from func_00453EB0, otherwise releases the entry. */
void func_0048AEB8(s32 arg0, s64 arg1) {
    u8 *v;
    s32 *w;

    v = func_0048A970((u32)arg1);
    if (v != NULL) {
        if (arg0 != 0) {
            w = func_00453EB0(*(s16 *)(v + 0xC));
            if (w != NULL) {
                *w = arg0;
                *(s32 *)v = arg0;
                v[8] = 3;
            }
        } else {
            func_0048A950(v);
        }
    }
}
