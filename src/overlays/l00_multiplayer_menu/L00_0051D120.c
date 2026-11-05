/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 {
    s32 unk0;
    char pad4[0x14];
    s32 (*unk18)(s32, char *, s32, s32, s32 *, s32);
    char pad1C[4];
    s32 unk20[4];
} Type1;

typedef struct Type2 {
    s32 unk0;
    char pad4[8];
    s32 unkC;
} Type2;

extern void func_L00_004F84C8(int, int, int, int, int);
extern void func_L00_005195A8(s32 arg0, char *arg1, s32 *arg2);
extern s32 func_L00_0051A740(void);
extern void func_L00_0051A7B8(s32);
extern s32 func_L00_00540F30(s32 arg0, Type1 **arg1);

s32 func_L00_0051D120(Type1 **arg0, s32 arg1, s32 *arg2, Type2 *arg3) {
    char buf[0x20];
    s32 sp20;
    s32 obj;
    s32 found;
    s32 i;
    Type1 *p;

    found = 0;
    *arg2 = 0;
    obj = func_L00_0051A740();
    if (obj == 0) {
        return 0;
    }
    func_L00_00540F30(obj, arg0);
    func_L00_005195A8(obj, buf, &sp20);
    p = *arg0;
    for (i = 0; i < 4 && p->unk20[i] != 0; i++) {
        if (arg3->unk0 == p->unk20[i]) {
            found = 1;
            break;
        }
    }
    if (found == 0) {
        func_L00_004F84C8(6, 0x7A, 0x7A, 0, 0);
    } else if (p->unk18 != 0) {
        func_L00_0051A7B8(obj);
        return (*arg0)->unk18((*arg0)->unk0, buf, sp20, arg1, arg2, arg3->unkC);
    } else {
        func_L00_004F84C8(6, 0x7A, 0x76, 0, 0);
    }
    if (obj != 0) {
        func_L00_0051A7B8(obj);
    }
    return 0;
}
