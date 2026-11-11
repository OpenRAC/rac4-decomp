/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_00540FC8(s32);
extern s32 func_L00_0051A740(void);
extern void *func_L00_004FACD8(s32);
extern void func_L00_004F84C8(s32, s32, s32, s32, s32);
extern s32 func_L00_00519490(s32, s32);
extern void func_L00_00519578(s32, void *, s32);
extern void func_0011A518(void *, s32, s32);
extern s32 func_L00_0051D278(s32, s32, s32, s32);
extern void func_004FAD28(void *);
extern void func_L00_0051A7B8(s32);

s32 func_L00_00537520(s32 (*fn)(s32, void *), s32 *key, s32 *info, s32 arg3, s32 arg4) {
    void *buf[4];
    s32 ret = -1;
    s32 h = 0;
    void *mem = NULL;
    s32 id;
    s32 size;

    id = func_00540FC8(*key);
    if (id == 0) {
        func_L00_004F84C8(0xD, 0x79, 0x8D, 0, 0);
    } else {
        h = func_L00_0051A740();
        if (h != 0) {
            size = fn(arg3, NULL);
            mem = func_L00_004FACD8(size);
            if (mem == NULL) {
                func_L00_004F84C8(0xD, 0x79, 0x21, 0, 0);
            } else {
                buf[0] = mem;
                fn(arg3, buf);
                if (func_L00_00519490(h, id) != 0) {
                    func_L00_00519578(h, mem, size);
                    func_0011A518(mem, 0, size);
                    if (func_L00_0051D278(h, info[2], info[0], arg4) > 0) {
                        ret = 1;
                    } else {
                        func_L00_004F84C8(0xD, 0x79, 0x806, 0, 0);
                        ret = 0;
                    }
                }
            }
        }
    }
    if (mem != NULL) {
        func_004FAD28(mem);
    }
    if (h != 0) {
        func_L00_0051A7B8(h);
    }
    return ret;
}
