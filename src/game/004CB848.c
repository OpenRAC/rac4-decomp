#include "common.h"

typedef struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 _pC[0x58];
} Type1;

extern void func_0049C290(s32 param, s32 count);
extern void func_0049C400(s32 slot, s32 offset, s32 param_a, s32 param_b, s32 mode);
extern void func_0049D170(s32 param_a, s32 param_b, s32 source);
extern void func_0049D280(s32 player, s32 count);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_004CB938(void);
extern void func_004CC148(s32 selection);
extern void func_004CC450(void);
extern void func_004CD008(void);
extern s32 func_00505B20(void);
extern s32 D_00221920;
extern Type1 D_0030EAA0[];

void func_004CB848(void) {
    s32 id = func_00505B20();
    Type1 *e = &D_0030EAA0[id];
    s32 v;
    e->f4 = -1;
    e->f0 = 1;
    func_004CC450();
    func_004CD008();
    func_004CB938();
    func_0049D170(id, 0, func_004A1A60(&D_00221920, 0x22));
    func_0049D280(id, 1);
    v = D_00221920;
    func_0049C400(id, 0, v, func_004A1A60(&D_00221920, 0x22), 0);
    if (e->f4 >= 0) {
        func_0049C290(id, 1);
    }
    func_004CC148(e->f4);
    e->f8 = 1;
}
