/* cflags: @ee296 -O2 -G8 */
#include "common.h"

typedef struct {
    s8 unk0;
    u8 pad[3];
    void *unk4;
    s32 unk8;
} S;

s32 func_01EA0EB8(s8, void *, s32, s32);
s32 func_01EA1028(s8, void *, s32, s32);

s32 func_01EA11F8(s32 arg0, S *arg1) {
    void *p;
    s32 r;

    p = arg1->unk4;
    if (p == 0 || *(s32 *)((char *)p + 0x468) == 2) {
        r = func_01EA0EB8(arg1->unk0, p, arg1->unk8, arg0);
        if (r != 0) {
            return r;
        }
    } else {
        r = func_01EA1028(arg1->unk0, p, arg1->unk8, arg0);
        if (r != 0) {
            return r;
        }
    }
    return 0;
}
