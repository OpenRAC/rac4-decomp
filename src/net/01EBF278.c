/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Type1 {
    u8 b[8];
} Type1;

typedef struct Type2 {
    s32 f0;
    u8 pad4[4];
    Type1 f8;
    s32 f10;
    u8 pad14[0x4A];
    u16 f5E;
    u8 pad60[0x2C];
    struct Type2 *f8C;
} Type2;

typedef struct Type3 {
    s32 f0;
    u8 pad4[8];
    Type2 *f0C;
    u8 pad10[0x34];
    s32 f44;
    u8 pad48[4];
    u8 f4C[8];
    s32 f54;
    u8 pad58[0x18];
    u32 f70;
} Type3;

extern void func_0011A518(void *, s32, s32);
extern void func_01EA7538();
extern void func_01EA7830(s32 a0, Type1 v, s32 a2, u16 *buf, s32 n, s32 *extra);
extern s32 func_01EAB270(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
extern s32 func_01EAB288(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
extern void func_01EAB2A0(void);
extern s32 func_01EBFED0(void *, void *);
extern s32 func_01EC0490(void *);
extern s32 func_01EC0580(void *);

// Walks the entry list at arg0->0xC, then the sub-object at arg0->0x4C, calling the helpers; returns the first non-zero result.
s32 func_01EBF278(Type3 *arg0) {
    u16 buf[8];
    u32 sp10;
    s32 extra;
    Type2 *s0;
    s32 ret;
    u8 *temp;

    ret = 0xD2F2;
    extra = 0;
    if (arg0 != NULL) {
        s0 = arg0->f0C;
        while (s0 != NULL) {
            if (s0->f0 != 0) {
                ret = func_01EBFED0(arg0, s0);
                if (ret != 0) {
                    return ret;
                }
            }
            if (s0->f0 == 0xD) {
                ((void (*)(void *, void *))func_01EAB2A0)((u8 *)s0 + 0x3C, &sp10);
                if (sp10 < 0x7D1) {
                } else {
                    func_0011A518(buf, 0, 6);
                    buf[0] |= s0->f5E & 0x3FF;
                    func_01EA7830(arg0->f0, s0->f8, s0->f10, buf, 6, &extra);
                    ((s32 (*)(void *))func_01EAB288)((u8 *)s0 + 0x3C);
                }
            }
            s0 = s0->f8C;
        }
        if (arg0->f44 != 0) {
            temp = arg0->f4C;
            ((void (*)(void *, void *))func_01EAB2A0)(temp, &sp10);
            if (!(sp10 < arg0->f70) || arg0->f54 != 0) {
                ret = func_01EC0490(arg0);
                if (ret != 0) {
                    return ret;
                }
                ((s32 (*)(void *))func_01EAB270)(temp);
                arg0->f54 = 0;
            }
        }
        func_01EA7538();
        ret = func_01EC0580(arg0);
    }
    return ret;
}
