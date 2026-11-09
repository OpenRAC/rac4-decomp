/* Not matching yet: BYTES 10/200 (tools/try_func.py func_004DC200 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    u8 f0;
    u8 pad[0x23];
} Type1;

extern void func_004A1170(void *arg0);
extern void func_004A1240(void *, s32);
extern void func_004A1440(void *, void *, s32);
extern void func_004DC2C8(void);
extern s32 func_004DC7D8(void);
extern s32 func_00505B20(void);
extern u8 D_322FC8[];
extern Type1 D_323130[];

void func_004DC200(void) {
    u8 *base;
    s32 i;
    u8 *obj;

    base = D_322FC8 + func_00505B20() * 0x168;
    func_004DC2C8();
    func_004A1170(base + 0xE4);
    for (i = 0; i < 9; i++) {
        if (D_323130[i].f0 != 0) {
            obj = base + 0xE4;
            func_004A1440(obj, &D_323130[i], -1);
        }
    }
    if (*(s32 *)(obj + 0x50) > 0) {
        func_004A1240(obj, func_004DC7D8());
    }
    *(s32 *)(base + 4) = (*(s32 *)(base + 4) | 2) & ~1;
}
