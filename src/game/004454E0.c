#include "common.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
    s32 pad0C;
    s32 pad10;
    s32 f14;
    s32 f18;
} S_4454E0;

extern void func_004E7830(s32);
extern s32 func_00138D70(s32);
extern void func_004E7638(void);
extern void func_004E4C50(s32);
extern S_4454E0 D_00235940;
extern s32 D_0023AB00[];
extern s32 D_002211CC;
extern f32 D_002211D0;
extern s32 D_00221E28;
extern s32 D_0021EDE8;
extern s32 D_0021DA34;

/* from rac2-decomp's func_00278EB0 */
void func_004454E0(void) {
    S_4454E0 *state;

    func_004E7830(1);
    func_00138D70(0);
    D_002211CC++;
    state = &D_00235940;
    state->f14 = D_00221E28 - 0x60000;
    state->x = D_0023AB00[3] + 0x60000;
    state->y = D_0023AB00[4] + 0x60000;
    state->z = state->x + 0xD0800;
    D_0021EDE8 = 0x2000;
    D_00221E28 = 0x60000;
    func_004E7638();
    func_004E4C50(1);
    state->f18 = D_0021DA34;
    D_002211D0 = 1.0f;
}
