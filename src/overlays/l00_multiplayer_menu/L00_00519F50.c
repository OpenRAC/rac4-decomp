/* cflags: @ee29 -O2 -G0 -mno-split-addresses -fno-strict-aliasing */
#include "common.h"

typedef struct {
    u8 pad0[8];
    s64 f8[16];
    s32 f88[16];
    s32 fC8[16];
    void *f108[16];
    s32 f148[16];
    s32 f188;
    s32 f18C;
} Type1;

extern Type1 *func_L00_004F86B0();
extern u8 D_004AD230[];
extern u8 D_004AD238[];

// Advances the ring cursor of the object, clears the new entry when arg0 is set, reports its pointers and returns the entry.
s64 func_L00_00519F50(s32 arg0, void **arg1, s32 *arg2, void **arg3, s32 *arg4) {
    Type1 *o;
    s32 slot;
    s64 r;
    void *t;

    o = func_L00_004F86B0();
    if (o->f18C == o->f188) {
        return 0;
    }
    slot = (o->f18C + 1) % 16;
    r = o->f8[slot];
    if (arg0 != 0) {
        o->f18C = slot;
        o->f8[slot] = 0;
    }
    if (arg1 != NULL) {
        if (arg2 != NULL) {
            t = o->f108[slot];
            if (t == NULL) {
                *arg1 = D_004AD230;
                *arg2 = 0;
            } else {
                *arg1 = t;
                *arg2 = o->f148[slot];
            }
        }
    }
    if (arg3 != NULL) {
        if (o->f88[slot] == 0) {
            *arg3 = D_004AD238;
            if (arg4 != NULL) {
                *arg4 = 0;
            }
        } else {
            *arg3 = (void *)o->f88[slot];
            if (arg4 != NULL) {
                *arg4 = o->fC8[slot];
            }
        }
    }
    return r;
}
