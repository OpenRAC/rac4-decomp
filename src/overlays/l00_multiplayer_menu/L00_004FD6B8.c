/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct H_004FD6B8 { s32 type; s32 pad4[2]; s32 unkC; } H_004FD6B8;
typedef struct O_004FD6B8 { s32 pad0; s32 *unk4; } O_004FD6B8;
extern H_004FD6B8 *func_L00_004F7BE0(s32);
extern void func_L00_004F84C8(int, int, int, int, int);
extern s32 func_L00_005266A0(s32, s32, s32, s32, s32);

s32 func_L00_004FD6B8(O_004FD6B8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 ret = -1;
    H_004FD6B8 *h;

    if (arg0 == NULL || *arg0->unk4 == 0 || (h = func_L00_004F7BE0(*arg0->unk4)) == NULL) {
        func_L00_004F84C8(0x14, 0xBC, 0xC0, 0, 0);
        return -1;
    }
    if (h->type != 6) {
        func_L00_004F84C8(0x14, 0xBC, 0xD1, 0, 0);
    } else {
        ret = func_L00_005266A0(arg1, arg2, arg3, h->unkC, arg4);
        if (ret < 0) {
            func_L00_004F84C8(0x14, 0xBC, 0x804, 0, 0);
        }
    }
    return ret;
}
