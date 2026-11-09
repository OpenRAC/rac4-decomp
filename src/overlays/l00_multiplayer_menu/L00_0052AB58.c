/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Type2;

typedef struct {
    s32 *unk0;
    Type2 *unk4;
} Type1;

extern s32 func_0011A2DC(s32, s32, s32);
extern void func_0011A518(void *, s32, s32);
extern void func_004FAD28(void *);
extern s32 func_005267D0(s32, s32, void *, s32, s32);
extern void func_L00_004F84C8(int, int, int, int, int);
extern void *func_L00_004FACD8(unsigned int);
extern s32 func_L00_0051CA88(s32 arg0);
extern s32 func_L00_005263A8(s32);
extern Type1 *func_L00_0052FC90(s32, void *, s32);
extern void func_L00_0052FEC8(Type1 *);

s32 func_L00_0052AB58(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void *buf[4];
    s32 ok = 0;
    Type1 *obj = 0;
    void *mem;
    s32 n;

    if (arg4 != func_L00_005263A8(arg5)) {
        func_L00_004F84C8(4, 0x7F, 0x75, 0, 0);
        return 0;
    }
    mem = func_L00_004FACD8(arg4);
    if (mem == 0) {
        func_L00_004F84C8(4, 0x7F, 0x21, 0, 0);
    } else {
        n = func_005267D0(arg4, arg3, mem, arg5, 1);
        if (n > 0) {
            buf[0] = mem;
            obj = func_L00_0052FC90(0, buf, n);
            if (obj != 0) {
                if (func_L00_0051CA88(*obj->unk0) != arg0) {
                    func_L00_004F84C8(4, 0x7F, 0x76, 0, 0);
                } else if (obj->unk4->unk0 != arg2 || func_0011A2DC(arg1, obj->unk4->unk8, arg2) != 0) {
                    func_L00_004F84C8(4, 0x7F, 0x67, 0, 0);
                } else {
                    ok = 1;
                }
            }
        }
    }
    if (obj != 0) {
        func_L00_0052FEC8(obj);
    }
    func_0011A518(mem, 0, arg4);
    func_004FAD28(mem);
    return ok;
}
