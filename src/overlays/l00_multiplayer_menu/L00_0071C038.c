#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern void func_0011A9EC(void *, void *);
extern s32 func_0011AB04(u8 *);
extern f32 func_L00_0069C148(s32 handle);

/* walks a string buffer advancing while the measured width is below a limit */
void func_L00_0071C038(u8 *arg0, s32 arg1, s32 arg2) {
    s32 off;
    u8 *base;
    u8 *p;
    f32 limit;
    f32 buf[4];
    off = arg1 * 4;
    base = arg0 + 0xB0;
    func_0011A9EC(arg0 + 0x5C, (void *)(*(s32 (**)(void *))(*(s32 *)(*(s32 *)(base + off) + 0x58) + 0xF4))(*(void **)(base + off)));
    p = arg0 + 0x5C;
    func_0011A518(buf, 0, 0x10);
    limit = func_L00_0069C148(arg2);
    if (arg0[0x5C] != 0) {
        if ((*(s32 (**)(void *, void *))(*(s32 *)(*(s32 *)(base + off) + 0x58) + 0x6C))(*(void **)(base + off), buf) != 0) {
            while (limit < buf[2] && func_0011AB04(p) != 0) {
                if ((*p ^ 0x80) == 0) {
                    p = p + 1;
                }
                p = p + 1;
                (*(void (**)(void *, u8 *))(*(s32 *)(*(s32 *)(base + off) + 0x58) + 0xE8))(*(void **)(base + off), p);
                (*(s32 (**)(void *, void *))(*(s32 *)(*(s32 *)(base + off) + 0x58) + 0x6C))(*(void **)(base + off), buf);
            }
        }
    }
}
