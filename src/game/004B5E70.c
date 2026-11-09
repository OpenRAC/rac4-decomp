#include "common.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4;

typedef struct {
    u8 f0;
    u8 pad1[3];
    s32 f4;
    s32 f8;
} Type2;

typedef struct {
    u8 pad0[0x194];
    Type2 f194[8];
    s32 f1F4;
} Type1;

extern s32 func_00497810(u32 index);
extern void func_0049F2F0(s32 arg0, s32 arg1);
extern void func_0049F660(s32 arg0, f32 x, f32 y, f32 z, f32 w);
extern void func_004A0040(s32 slot, s32 count, Type2 *items);
extern void func_004A0198(s32 index, const char *text);
extern void func_004A01D8(s32 arg0, s8 arg1);

extern u8 D_00171DF5[];
extern s32 D_0021EDD4;
extern Vec4 D_003D9320[];
extern Type1 D_003098F0[];

f32 D_0021F7F0 = 0.5f;
f32 D_0021F7F4 = 0.5f;
f32 D_0021F7F8 = 0.529296875f;
f32 D_0021F7FC = 0.048076923936605453f;
f32 D_0021F800 = 0.25f;
f32 D_0021F804 = 0.25f;
f32 D_0021F808 = 0.41015625f;
f32 D_0021F80C = 0.03846153989434242f;

void func_004B5E70(s32 arg0, s32 arg1, const char *arg2)
{
    Type1 *rec = &D_003098F0[arg0];
    Vec4 *col = &D_003D9320[func_00497810(arg0)];

    if (D_00171DF5[0] == 4) {
        if (func_00497810(arg0) == 2) {
            col = (Vec4 *)&D_0021F7F0;
        }
        if (func_00497810(arg0) == 4) {
            col = (Vec4 *)&D_0021F800;
        }
    }
    func_004A0198(arg0, arg2);
    func_0049F660(arg0, col->x, col->y, col->z, col->w);
    func_004A01D8(arg0, D_0021EDD4 != 1);
    func_004A0040(arg0, rec->f1F4, rec->f194);
    func_0049F2F0(arg0, arg1);
}
