#include "common.h"

typedef struct {
    u8 pad[0x154];
    s8 f154[0xA4];
} Type1;

extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern s32 func_0045E038(s32);
extern u16 D_00171D3C[];
extern char D_0021F820[];
extern Type1 D_3098F0[];

// Calls func_0011D920 with the record at arg0 of D_3098F0, the tag string at D_0021F820, and two values from func_0045E038.
void func_004B5D68(s32 arg0) {
    Type1 *rec;
    s8 *name;
    char *temp_s2;
    s32 temp_s3;
    s32 temp_s0;

    rec = &D_3098F0[arg0];
    temp_s0 = D_00171D3C[0] != 0;
    temp_s2 = D_0021F820;
    name = rec->f154;
    temp_s3 = func_0045E038(0x234D);
    func_0011D920(name, temp_s2, temp_s3, func_0045E038((temp_s0 != 0) ? 0x175 : 0x176));
}
