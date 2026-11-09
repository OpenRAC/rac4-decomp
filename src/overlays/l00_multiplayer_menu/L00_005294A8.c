/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_0011A2DC(s32, s32, s32);
extern void func_0011A518(void *, s32, s32);
extern void func_004FAD28(void *);
extern s32 func_005267D0(s32, s32, void *, s32, s32);
extern void func_005362F8(void *);
extern void func_L00_004F84C8(s32, s32, s32, s32, s32);
extern void *func_L00_004FACD8(s32);
extern s32 func_L00_005263A8(s32);
extern s32 *func_L00_00536A78(s32, void **, s32);

s32 func_L00_005294A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 size, s32 arg5) {
    void *stack[4];
    s32 result;
    s32 *entry;
    void *buf;
    s32 n;

    result = 0;
    entry = NULL;
    if (size != func_L00_005263A8(arg5)) {
        func_L00_004F84C8(4, 0x81, 0x75, 0, 0);
        return 0;
    }
    buf = func_L00_004FACD8(size);
    if (buf == NULL) {
        func_L00_004F84C8(4, 0x81, 0x21, 0, 0);
    } else {
        n = func_005267D0(size, arg3, buf, arg5, 1);
        if (n > 0) {
            stack[0] = buf;
            entry = func_L00_00536A78(0, stack, n);
            if (entry != NULL) {
                if (entry[0] != arg2 || func_0011A2DC(arg1, entry[2], arg2) != 0) {
                    func_L00_004F84C8(4, 0x81, 0x67, 0, 0);
                } else {
                    result = 1;
                }
            }
        }
    }
    if (entry != NULL) {
        func_005362F8(entry);
    }
    func_0011A518(buf, 0, size);
    func_004FAD28(buf);
    return result;
}
