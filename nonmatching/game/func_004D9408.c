/* Not matching yet: BYTES 6/236 (tools/try_func.py func_004D9408 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
} Type4;
typedef struct {
    char pad0[8];
    Type4 *f8;
    char pad0C[0xC];
} Type3;
typedef struct {
    char pad0[0x34];
    Type3 *f34;
    char pad38[0x18];
    s32 f50;
    s32 f54;
} Type1;
typedef struct {
    char pad0[8];
    s32 f8;
    s32 fC;
} Type2;

extern s32 func_00505B20(void);
extern s32 func_00499CA0(void *, s32);
extern void func_00499CE0(s32);
extern s32 func_004A1A60(s32 *, s32);
extern s32 func_00506120(s32, s32);
extern s32 func_00505238(s32, s32);
extern u8 D_00321140[];
extern char D_001CE2F8[];
extern s32 D_00221B48;

void func_004D9408(void) {
    Type2 *rec;
    Type1 *blk;
    Type3 *ent;
    Type4 *s1;
    s32 idx;

    rec = (Type2 *)(D_00321140 + func_00505B20() * 0x114);
    blk = (Type1 *)((u8 *)rec + 0xA8);
    if (blk->f50 > 0) {
        idx = blk->f54;
        ent = 0;
        if (idx >= 0) {
            ent = &blk->f34[idx];
        }
        s1 = ent->f8;
        if (rec->fC != 0) {
            func_00499CE0(rec->fC);
            rec->fC = 0;
        }
        rec->fC = func_00499CA0(D_001CE2F8 + s1->f4 * 8, -1);
        func_00506120(func_004A1A60(&D_00221B48, 2), rec->fC);
        func_00505238(func_004A1A60(&D_00221B48, 6), s1->f0);
    }
    rec->f8 &= ~2;
}
