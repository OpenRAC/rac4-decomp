/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EA42D8(s32);
extern u16 *func_01ED0BE0(void *, u8);
extern s32 D_00167F3C[];

typedef struct Type1 {
    u8 pad0[0x14];
    u32 f14;
    u8 pad1[0x60];
    u8 f78;
    s32 f7C;
} Type1;

typedef struct Type3 {
    u8 pad0[0x14];
    s32 f14;
} Type3;

typedef struct Type2 {
    u8 pad0[0x474];
    s32 f474;
    u8 pad1[0x10];
    Type3 *f488;
} Type2;

typedef struct Type4 {
    u8 pad0[0x70];
    s32 (*f70)(s32, u8, u32 *);
} Type4;

extern Type1 *func_01ED2458(Type2 *arg0);

// Looks the record up through the table and sets *arg1 to 1 when it matches.
s32 func_01ED01C0(Type2 *arg0, s32 *arg1) {
    u32 sp0;
    s32 var_s3;
    s32 r;
    Type1 *temp_s0;
    u16 *temp_v0_2;
    u16 *var_a0;
    u32 temp_a1;
    u32 var_a2;
    Type4 *obj;

    var_s3 = 0;
    if (arg1 == 0) {
        return 0x17;
    }
    temp_s0 = func_01ED2458(arg0);
    if (temp_s0 == 0) {
        return 0x17;
    }
    temp_v0_2 = func_01ED0BE0(arg0, temp_s0->f78);
    if (temp_v0_2 != 0) {
        temp_a1 = temp_s0->f14;
        var_a2 = 0;
        if (temp_a1 != 0) {
            var_a0 = temp_v0_2;
            do {
                if (*var_a0 == 0xFFFE) {
                    var_s3 = 1;
                }
                var_a0++;
                var_a2++;
            } while (var_a2 < temp_a1);
        }
    }
    obj = (Type4 *)D_00167F3C[0];
    r = func_01EA42D8(obj->f70(arg0->f474, temp_s0->f78, &sp0));
    if (r != 0) {
        return r;
    }
    if (sp0 < 2) {
        *arg1 = 0;
    } else if (temp_s0->f7C != 0) {
        *arg1 = 1;
    } else if (var_s3 != 0) {
        *arg1 = 1;
    } else if (arg0->f488->f14 + 1 == sp0) {
        *arg1 = 1;
    } else {
        *arg1 = 0;
    }
    return 0;
}
