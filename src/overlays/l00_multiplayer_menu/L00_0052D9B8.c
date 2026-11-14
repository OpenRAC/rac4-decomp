/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_L00_0052DAA0(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_L00_00541CB8();
extern void func_L00_00541D98(void *);

/* Walks the list at arg0 for the first entry the helper accepts and copies it to arg3; returns 1 on a hit, 0 when none, or the helper's negative result. */
s32 func_L00_0052D9B8(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    s32 sp[2];
    void *s4;
    void *s1;
    void *v1;
    s32 s0;
    s32 v0;

    s4 = *(void **)arg0;
    s1 = (void *)func_L00_0052DAA0(*(s32 *)((u8 *)s4 + 4), arg1, arg2);
    if (s1 == NULL) {
        s0 = *(s32 *)((u8 *)arg0 + 4);
        for (;;) {
            v1 = *(void **)((u8 *)s4 + 8);
            if (s0 >= *(s32 *)v1) {
                break;
            }
            v0 = func_L00_00541CB8(*(s32 *)(*(u8 **)((u8 *)v1 + 4) + s0 * 4), arg1, arg2, sp);
            if (v0 < 0) {
                *(s32 *)((u8 *)arg0 + 4) = v0;
                return v0;
            }
            s0 += 1;
            if (v0 != 0) {
                s1 = sp;
                break;
            }
        }
        *(s32 *)((u8 *)arg0 + 4) = 0;
        if (s1 == NULL) {
            return 0;
        }
    }
    *(s32 *)arg3 = *(s32 *)s1;
    *(s32 *)((u8 *)arg3 + 4) = *(s32 *)((u8 *)s1 + 4);
    func_L00_00541D98(arg3);
    return 1;
}
