/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_004FAD28(void *);
extern void *func_L00_004FACD8(unsigned int);
extern s32 func_L00_005363C0(s32, u8 **);
extern u8 *func_L00_00541000(s32 arg0, s32 arg1, u8 *arg2);

u64 func_L00_0052D600(s32 arg0) {
    u8 hash[16];
    u8 buf[256];
    u8 *ptr;
    u8 *p;
    s32 size;

    size = func_L00_005363C0(arg0, 0);
    if (size > 256) {
        p = func_L00_004FACD8(size);
    } else {
        p = buf;
    }
    ptr = p;
    func_L00_005363C0(arg0, &ptr);
    func_L00_00541000((s32)p, size, hash);
    if (p != buf) {
        func_004FAD28(p);
    }
    return hash[0] | ((u64)hash[1] << 8) | ((u64)hash[2] << 16) | ((u64)hash[3] << 24);
}
