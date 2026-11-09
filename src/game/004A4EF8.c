#include "common.h"

typedef struct {
    s32 flags;
    u8 pad[0xCC];
    f32 unkD0;
    u8 pad2[0x18];
} Type307B58;

typedef struct {
    f32 a;
    f32 b;
} Type3D1618;

extern s32 func_0011AB04(u8 *);
extern s32 func_00497810(u32 index);
extern void func_004978E0(s32 arg0, s32 arg1);
extern void func_00497908(s32 arg0, s32 arg1);
extern s32 func_00504740(s32 handle, float *a, float *b);
extern s32 func_00505238(u32, const char *);
extern s32 func_00505410(u32 id, f32 amount);
extern s32 func_005058E0(u32 id, f32 a, f32 b);
extern void func_00505AD8(s32 a);
extern s32 func_00505B20(void);

extern f32 D_003D1600[];
extern Type3D1618 D_003D1618[];
extern Type307B58 D_00307B58[];

void func_004A4EF8(s32 arg0, u8 *str) {
    f32 pos[2];
    s32 saved;
    s32 found;
    s32 len;
    s32 i;
    u8 c;

    saved = func_00505B20();
    func_00505AD8(arg0);
    if (str != 0) {
        found = 0;
        len = func_0011AB04(str);
        for (i = 0; i < len; i++) {
            c = str[i];
            if (c == 0x12 || c == 0x10) {
                found = 1;
                break;
            }
        }
        if (found) {
            D_00307B58[arg0].unkD0 = D_003D1618[func_00497810(arg0)].a;
            func_004978E0(arg0, 0x40);
        } else {
            D_00307B58[arg0].unkD0 = D_003D1618[func_00497810(arg0)].b;
            func_00497908(arg0, 0x40);
        }
        pos[1] = pos[0] = 0.0f;
        D_00307B58[arg0].flags |= 1;
        func_00505238(0xE0001, 0);
        func_00505238(0xE0001, (const char *)str);
        func_00504740(0xE0001, &pos[0], &pos[1]);
        func_005058E0(0xE0001, D_003D1600[func_00497810(arg0)], pos[1]);
        func_005058E0(0xE0002, pos[0] + 0.045f, pos[1] + 0.03f);
        func_005058E0(0xE0003, pos[0] + 0.045f, pos[1] + 0.03f);
        func_00505410(0xE0002, 1.0f);
        func_00505410(0xE0001, 1.0f);
        func_00505410(0xE0003, 1.0f);
    }
    func_00505AD8(saved);
}
