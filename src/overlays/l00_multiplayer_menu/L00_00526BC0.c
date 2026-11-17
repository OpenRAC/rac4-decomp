/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_L00_00519490(void *, s32);
extern void func_L00_00519578(void *arg0, s32 arg1, u32 arg2);
extern void func_L00_005195A8(void *arg0, s32 arg1, s32 *arg2);
extern s32 func_L00_0051A718(void *arg0);

// Packs the low word of a stored value into bytes, then sends the menu fields through the call chain.
void func_L00_00526BC0(u8 *arg0, s32 arg1, s32 arg2) {
    u8 buf[4];
    void *s1;
    s32 s2, s3, s4;
    u64 x;

    if (arg2 != 0) {
        s1 = *(void **)(arg0 + 0x78);
        x = *(u64 *)(*(u8 **)(arg0 + 0x50) + 0xE0);
        s2 = *(s32 *)(*(u8 **)(arg0 + 0x50) + 0x68);
        s3 = *(s32 *)(*(u8 **)(arg0 + 0x50) + 0x50);
        s4 = *(s32 *)(*(u8 **)(arg0 + 0x50) + 0x58);
    } else {
        s1 = *(void **)(arg0 + 0x6C);
        x = *(u64 *)(*(u8 **)(arg0 + 0x50) + 0xD8);
        s2 = *(s32 *)(*(u8 **)(arg0 + 0x50) + 0x64);
        s3 = *(s32 *)(*(u8 **)(arg0 + 0x50) + 0x48);
        s4 = *(s32 *)(*(u8 **)(arg0 + 0x50) + 0x54);
    }
    buf[0] = (u8)((x >> 24) & 0xFF);
    buf[1] = (u8)((x >> 16) & 0xFF);
    buf[2] = (u8)((x >> 8) & 0xFF);
    buf[3] = (u8)(x & 0xFF);
    func_L00_00519490(s1, 0);
    func_L00_00519578(s1, s2, func_L00_0051A718(*(void **)(arg0 + 0x70)));
    func_L00_00519578(s1, s4, s3);
    func_L00_00519578(s1, (s32)buf, 4);
    func_L00_005195A8(s1, arg1, 0);
}
