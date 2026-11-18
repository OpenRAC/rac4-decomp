/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_01EA06A8(void *);
extern s32 func_01EA6D00(void *arg0);
extern void *func_01EC9A28(u8 arg0);
extern s32 func_01EC9B08(s32 *out, void *ctx);
extern u8 *D_00167F38[];

/* Looks up the record for the byte at arg3; for a type-2 record it runs the hook from its table and either flags the record active or resets it. */
s32 func_01ECED98(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3) {
    s32 sp0;
    u8 *s1;
    u8 **pd;
    void (**hooks)(s32, u8);
    void (*fp)(s32, u8);

    sp0 = 0x100;
    if (arg0 == NULL) {
        return -1;
    }
    s1 = func_01EC9A28(*arg3);
    if (s1 == NULL) {
        return 1;
    }
    if (s1[0] == 2) {
        pd = D_00167F38;
        hooks = *(void (***)(s32, u8))(*pd + 0x174);
        fp = hooks[s1[3]];
        if (fp != NULL) {
            fp(arg2, *arg3);
        }
        func_01EC9B08(&sp0, arg0);
        if (*(s32 *)(arg0 + 0x404) == sp0 && s1[5] != 0 && (*(s32 **)(*pd + 0x178))[s1[3]] != 0) {
            s1[4] = 1;
        } else {
            s1[0] = 1;
            if (s1[2] != 0) {
                func_01EA06A8(s1 + 0x10);
                func_01EA6D00(s1 + 0x2C);
                *(s32 *)(s1 + 0x10) = 0;
                *(s32 *)(s1 + 0x14) = 0;
            }
        }
    }
    return 1;
}
