/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern void func_0011EAA0(char *file, s32 line, char *expr);
extern s32 func_01EE15D8(void *);
extern void func_01EE1A10(void *);
extern s32 func_01EE1AE8(void *, void *, s32);
extern s32 func_01EE3070(void *);
extern void *D_0016AC20;
extern char D_0019A510[];
extern char D_0019A9A0[];
extern char D_0019A9E8[];
extern char D_0019AA10[];

/* Allocates a 0x308-byte record through arg1 (after a one-time setup of D_0016AC20 when arg0 is not 0x80), stores arg0, arg2 and arg3 in it, and returns it or NULL. */
void *func_01EE18D0(arg0, arg1, arg2, arg3)
s32 arg0;
void *(*arg1)();
s32 arg2;
s32 arg3;
{
    void **p;
    s32 temp_s1;
    void *temp_v0;
    void *temp_v0_2;
    void *var_v0;

    var_v0 = NULL;
    if (arg1 != NULL) {
        if (arg0 != 0x80) {
            p = (void **) &D_0016AC20;
            if (*p == NULL) {
                temp_v0 = func_01EE18D0(0x80);
                if (func_01EE1AE8(temp_v0, D_0019A510, 0x3BE) != 0x3BE) {
                    func_0011EAA0(D_0019A9A0, 0x201, D_0019A9E8);
                }
                temp_s1 = func_01EE3070(temp_v0);
                if (func_01EE15D8(temp_v0) == 0) {
                    func_01EE1A10(temp_v0);
                } else {
                    *p = temp_v0;
                }
                if (temp_s1 != 0xD4) {
                    func_0011EAA0(D_0019A9A0, 0x20F, D_0019AA10);
                }
            }
        }
        temp_v0_2 = arg1(0x308);
        if (temp_v0_2 != NULL) {
            func_0011A518(temp_v0_2, 0, 0x308);
            ((s32 *) temp_v0_2)[5] = arg0;
            ((s32 *) temp_v0_2)[3] = arg2;
            ((s32 *) temp_v0_2)[10] = arg3;
        }
        var_v0 = temp_v0_2;
    }
    return var_v0;
}
