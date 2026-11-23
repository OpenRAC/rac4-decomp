/* Not matching yet: BYTES 18/184 (tools/try_func.py func_004996D8 --diff). Not part of the build. */
/* cflags: -fno-schedule-insns2 -O3 */
#include "common.h"

typedef struct Type2 {
    u8 pad0[4];
    s32 f4;
} Type2;

typedef struct Type1 {
    Type2 *f0;
    s32 f4;
} Type1;

typedef struct Type6 {
    s32 head;
    s32 tail;
    s32 count;
    Type1 *ring[8];
} Type6;

extern void func_001638E8(void);
extern void func_004A2D90(s32, s32, s32);
extern Type6 D_002F3BD0;
s32 D_0021F5F0 = 0;

void func_004996D8(s32 arg0, s32 arg1) {
    Type1 *e;

    if (arg1 == 1) {
        if (++D_0021F5F0 >= 6) {
            D_0021F5F0 = 0;
            func_001638E8();
        }
    } else {
        if (arg1 == 0) {
            e = D_002F3BD0.ring[D_002F3BD0.head];
            if (e->f0 != 0) {
                func_004A2D90(e->f4, e->f0->f4, 0);
            }
        }
        D_0021F5F0 = 0;
        D_002F3BD0.head = (D_002F3BD0.head + 1) % 8;
        D_002F3BD0.count--;
    }
}
