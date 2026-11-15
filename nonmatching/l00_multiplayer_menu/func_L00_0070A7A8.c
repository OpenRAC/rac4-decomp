/* Not matching yet: BYTES 7/96 (tools/try_func.py func_L00_0070A7A8 --diff). Not part of the build. */
#include "common.h"

extern s32 D_003F3D68[];
s32 D_00220A44 = 0x73;
s32 D_00220A48 = -1;
extern void func_0011A9EC(void *, void *);
extern void func_L00_00709AC8(void *);
extern void func_L00_0070A830(void);

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

void func_L00_0070A7A8(void) {
    State s;

    s.f0 = D_003F3D68[0];
    s.f4 = 1;
    s.f8 = D_00220A48;
    func_0011A9EC(s.name, D_002233A4->f3C + 4);
    D_00220A44 = -1;
    D_00220A48 = -1;
    func_L00_0070A830();
    func_L00_00709AC8(&s);
}
