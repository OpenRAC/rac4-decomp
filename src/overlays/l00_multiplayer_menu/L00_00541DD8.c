/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_004FAD28(s32);
extern void func_00541DB8(void *);
extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
extern void *func_L00_004F8A38(s32, void *);
extern void func_L00_004F8B28(s32, void *);
extern s32 func_L00_004FAAC0(s32, s32, void *, s32);
extern void *func_L00_004FACD8(s32);
extern void func_L00_00541D98(void *);
extern char D_004B05B8[];

typedef struct P { s32 f0; s32 f4; } P;
typedef struct R { u8 pad[4]; s32 f4; } R;

// Allocate a node for arg1, insert it into arg0's list and roll back if it replaced an entry.
s32 func_L00_00541DD8(R *arg0, s32 arg1) {
    s32 ret = 1;
    P *p;
    void *old;
    if (arg1 == 0) return 0;
    p = func_L00_004FACD8(8);
    if (p == 0) {
        func_L00_004F84C8(0xB, 0xE8, 0x21, 0, 0);
        return 0;
    }
    p->f4 = arg1;
    p->f0 = 1;
    func_L00_004FAAC0(9, 0xB, D_004B05B8, 0x48);
    func_L00_00541D98(p);
    old = func_L00_004F8A38(arg0->f4, p);
    if (old != 0) {
        ret = 0;
        func_L00_004F8B28(arg0->f4, p);
        func_00541DB8(p);
        func_004FAD28((s32)p);
        func_L00_004F8A38(arg0->f4, old);
        func_L00_004F84C8(0xB, 0xE8, 0x9B, 0, 0);
    }
    func_L00_004FAAC0(0xA, 0xB, D_004B05B8, 0x57);
    return ret;
}
