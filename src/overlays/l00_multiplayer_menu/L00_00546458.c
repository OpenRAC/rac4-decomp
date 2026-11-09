/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x4];
    s32 f4;
    void *f8;
};

extern s32 func_L00_005355D0(s32, void *);
extern void func_L00_00535E08(void *, s32, s32, s32, s32);
extern s32 func_L00_00535FB0(s32, s32, s32);
extern s32 func_L00_00551DD0(void *arg0, s32 arg1);

/* Computes a combined size of two parts, then optionally serializes both into a cursor. */
s32 func_L00_00546458(Type1 *arg0, s32 *arg1) {
    s32 cur;
    s32 size;
    s32 ret;

    if (arg0 == NULL) {
        return 0;
    }
    size = func_L00_005355D0(arg0->f4, NULL);
    size += func_L00_00551DD0(arg0->f8, 0);
    ret = func_L00_00535FB0(1, size, 0x10);
    if (arg1 == NULL) {
        return ret;
    }
    cur = *arg1;
    func_L00_00535E08(&cur, 1, size, 0x10, 0);
    func_L00_005355D0(arg0->f4, &cur);
    func_L00_00551DD0(arg0->f8, (s32)&cur);
    *arg1 = cur;
    return ret;
}
