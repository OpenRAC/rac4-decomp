#include "common.h"

typedef struct Type2 {
    u8 pad0[0x54];
    s32 f54;
} Type2;

typedef struct Type1 {
    u8 pad0[0x1C];
    Type2 *f1C;
} Type1;

typedef struct Type3 {
    s32 f0;
    s32 f4;
    u8 pad8[4];
    s16 fC;
} Type3;

extern s32 func_01EC94C0(void *arg0);
extern s32 D_01F31380[];
s32 D_0021DFEC = 0;

/* Bumps the global counter, looks up a slot through func_01EC94C0, and on a hit marks its entry and clears the flag at +4. */
void func_0015F228(void) {
    Type1 *obj;
    Type3 *elem;

    D_0021DFEC = D_0021DFEC + 1;
    obj = 0;
    if (func_01EC94C0(&obj) == 0) {
        elem = (Type3 *)((u8 *)D_01F31380 + obj->f1C->f54 * 0xAD0);
        if (elem != 0) {
            elem->fC = 1;
            if (elem->f4 != 0) {
                elem->f4 = 0;
            }
        }
    }
}
