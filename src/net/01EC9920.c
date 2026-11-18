/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0xA]; u8 fA; char _pB[5]; u32 f10; } Ent;
typedef struct { char _p0[0x100]; u32 f100; } Tbl;
typedef struct { char _p0[0x404]; u32 f404; } Obj;
extern s32 func_01EC98E8(u32 arg0);
extern Tbl *D_00167F38;
extern Obj *D_1B7390[];

// Counts the table entries matching the current object and stores the count in *arg0.
s32 func_01EC9920(u16 *arg0) {
    u32 var_s1;
    Obj *temp_s2;
    Ent *temp_v0;

    var_s1 = 0;
    if (arg0 == 0) {
        return 0x17;
    }
    *arg0 = 0;
    temp_s2 = D_1B7390[0];
    if (temp_s2 == 0) {
        return 0;
    }
    if (temp_s2->f404 == 0x100) {
        return 8;
    }
    while (var_s1 < D_00167F38->f100) {
        temp_v0 = (Ent *) func_01EC98E8(var_s1);
        var_s1 += 1;
        if (temp_v0 != 0 && (u8) (temp_v0->fA + 0xFD) < 2) {
            if (temp_s2->f404 == temp_v0->f10) {
                *arg0 += 1;
            }
        }
    }
    return 0;
}
