/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef s32 (*Fn0)(s32, char *, s32, s32, s32, s32);

typedef struct {
    s32 unk0;
    char pad4[0x18];
    Fn0 unk1C;
    s32 unk20[4];
} Type0;

typedef struct {
    s32 unk0;
    char pad4[8];
    s32 unkC;
} Type1;

extern void func_L00_004F84C8(int, int, int, int, int);
extern void func_L00_005195A8(s32 arg0, char *arg1, s32 *arg2);
extern s32 func_L00_0051A740(void);
extern void func_L00_0051A7B8(s32);
extern s32 func_L00_00540F30(s32 arg0, Type0 **arg1);

s32 func_L00_0051D278(Type0 **arg0, s32 arg1, s32 arg2, Type1 *arg3) {
    char buf[0x20];
    s32 sp20;
    s32 i;
    s32 found;
    s32 obj;
    Type0 *p;

    found = 0;
    obj = 0;
    p = *arg0;
    for (i = 0; i < 4 && p->unk20[i] != 0; i++) {
        if (arg3->unk0 == p->unk20[i]) {
            found = 1;
            break;
        }
    }
    if (found == 0) {
        func_L00_004F84C8(6, 0x7B, 0x7A, 0, 0);
    } else {
        obj = func_L00_0051A740();
        if (obj == 0) return -1;
        if (func_L00_00540F30(obj, arg0) != 0) {
            func_L00_005195A8(obj, buf, &sp20);
            if ((*arg0)->unk1C != 0) {
                func_L00_0051A7B8(obj);
                return (*arg0)->unk1C((*arg0)->unk0, buf, sp20, arg1, arg2, arg3->unkC);
            }
            func_L00_004F84C8(6, 0x7B, 0x77, 0, 0);
        }
    }
    if (obj != 0) {
        func_L00_0051A7B8(obj);
    }
    return -1;
}
