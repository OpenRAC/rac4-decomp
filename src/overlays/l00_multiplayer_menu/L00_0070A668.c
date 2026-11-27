#include "common.h"

extern char *func_0011A9EC(char *, char *);
extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern s32 func_L00_005C9F50(s32);
extern s32 func_L00_00709AC8(void *);
extern void func_L00_0070A010(s32, s32);

extern s32 D_003F3D58[];

typedef struct {
    s8 pad[0x3C];
    s8 *f3C;
} Glob;
extern Glob *D_002233A4;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s8 pad[0xF];
    s8 name[0x1A0 - 0x1B];
} State;

typedef struct Obj {
    s32 f0;
    s32 f4;
    s32 f8;
    s8 pad[0x19C - 0xC];
    struct Obj *f19C;
} Obj;

s32 D_00220A44 = 0x73;
s32 D_00220A48 = -1;
Obj *D_00220A10 = 0;
u8 D_00220A5C = 0;

s32 func_L00_0070A668(s32 arg0, s32 arg1) {
    State s;
    State t;
    Obj *var_s2;
    s32 ret;

    s.f0 = D_003F3D58[0];
    s.f4 = 1;
    s.f8 = arg1;
    func_0011A9EC(s.name, (char *)D_002233A4->f3C + 4);
    D_00220A44 = arg0;
    D_00220A48 = arg1;
    ret = func_L00_00709AC8(&s);
    if (ret == 0) {
        D_00220A44 = -1;
        D_00220A48 = -1;
    } else if (D_00220A5C != 0) {
        var_s2 = D_00220A10;
        if (var_s2 != 0) {
            while (1) {
                if (var_s2->f0 == D_003F3D58[0]) {
                    t.f8 = var_s2->f8;
                    t.f0 = D_003F3D58[3];
                    t.f4 = 1;
                    func_0011D920(t.name, (s8 *)func_L00_005C9F50(0x33E2),
                                  (s8 *)D_002233A4->f3C + 4);
                    func_L00_00709AC8(&t);
                    func_L00_0070A010(D_003F3D58[0], var_s2->f8);
                    D_00220A5C = 0;
                    break;
                } else {
                    var_s2 = var_s2->f19C;
                    if (var_s2 == 0) {
                        break;
                    }
                }
            }
        }
    }
    return ret;
}
