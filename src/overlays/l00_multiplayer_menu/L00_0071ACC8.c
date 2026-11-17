#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern s32 func_0011A9EC(void *, void *);
extern s32 func_0011AB04(u8 *);
extern f32 func_L00_0069C148(s32 handle);

// Refreshes the text at +0x28C from a virtual getter, counts it, then scrolls it while a float test holds.
void func_L00_0071ACC8(u8 *arg0) {
    u8 buf[16];
    u8 *s;
    u8 *temp;
    u8 *vt;
    f32 limit;

    temp = *(u8 **)(arg0 + 0xB4);
    vt = *(u8 **)(temp + 0x58);
    s = arg0 + 0x28C;
    func_0011A9EC(s, (*(void *(**)(u8 *))(vt + 0xF4))(temp));
    *(s32 *)(arg0 + 0x354) = 0;
    while (*s != 0) {
        s++;
        *(s32 *)(arg0 + 0x354) += 1;
    }
    s = arg0 + 0x28C;
    func_0011A518(buf, 0, 16);
    limit = func_L00_0069C148(*(s32 *)(arg0 + 0x240) | 5);
    if (*(s32 *)(arg0 + 0x354) > 0
        && (*(s32 (**)(u8 *, u8 *))(*(u8 **)(*(u8 **)(arg0 + 0xB4) + 0x58) + 0x6C))(*(u8 **)(arg0 + 0xB4), buf) != 0) {
        while (limit < *(f32 *)(buf + 8) && func_0011AB04(s) != 0) {
            if (*s == 0x80) {
                s++;
            }
            s++;
            (*(void (**)(u8 *, u8 *))(*(u8 **)(*(u8 **)(arg0 + 0xB4) + 0x58) + 0xE8))(*(u8 **)(arg0 + 0xB4), s);
            (*(s32 (**)(u8 *, u8 *))(*(u8 **)(*(u8 **)(arg0 + 0xB4) + 0x58) + 0x6C))(*(u8 **)(arg0 + 0xB4), buf);
        }
    }
}
