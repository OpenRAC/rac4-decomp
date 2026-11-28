#include "common.h"
#include "pal/global_00222894.h"
#include "pal/l01_0046DD08.h"
#include "pal/moby_class.h"
#include "pal/object_data.h"

extern u8 *D_L02_002228AC;
extern s32 func_L01_0058A000(u8 *);
extern void func_L00_006EE580(u8 *);
extern void func_00474368(u8 *, s32, s32);
extern s32 func_00453CE8(s32 *);
extern s32 func_L01_00589E70(u8 *);
extern s32 func_0045E850(s32);
extern void func_L01_005DBFA0(s32, s32, s32);
extern void func_L01_005DBFC8(s32, s32, s32, s32);

/* First-seen setup and per-state counters for class 0x2402, then the two status lines. */
void func_L02_004D13D8(u8 *moby) {
    u8 *vars;
    u8 *scan;
    u8 *cursor;
    void *entry;
    s32 (*fn)(u8 *);
    s32 fresh;

    if (func_L01_0058A000(moby) != 0) {
        return;
    }
    vars = (u8 *)((PalObject *)moby)->data;
    if (moby[0x20] == 0) {
        if (((moby[0xBE] ^ 1) & 1) != 0) {
            moby[0xBE] |= 1;
            fresh = 1;
        } else {
            fresh = 0;
        }
        if (fresh != 0) {
            moby[0x30] = 0xFF;
            *(s32 *)(vars + 0x70) = (s32)((f32)*(s32 *)(vars + 0x6C) * 50.0f);
            func_L00_006EE580(moby);
            moby[0x31] = 0;
            *(u16 *)(moby + 0x34) |= 1;
            for (scan = D_00222894; scan < D_L02_002228AC; scan += 0x100) {
                if (((PalMobyClassView *)scan)->classId == 0x2402) {
                    *(s32 *)(vars + 0x74) += 1;
                }
            }
        } else {
            func_00474368(moby, 1, -1);
        }
    } else if (moby[0x20] == 1) {
        if (*(s32 *)(vars + 0x6C) > 0) {
            func_00453CE8((s32 *)(vars + 0x70));
        }
        *(s32 *)(vars + 0x78) = 0;
        for (cursor = D_00222894; cursor < D_L02_002228AC; cursor += 0x100) {
            if (((PalMobyClassView *)cursor)->classId == 0x2402) {
                entry = func_0046DD08(0x2402, 0x14, 8);
                if (entry != 0) {
                    fn = *(s32 (**)(u8 *))((u8 *)entry + 4);
                    if (fn != 0 && fn(cursor) != 0) {
                        *(s32 *)(vars + 0x78) += 1;
                    }
                }
            }
        }
        if (func_L01_00589E70(moby) != 0) {
            func_00474368(moby, 2, -1);
        }
    }
    if (*(s32 *)(vars + 0x6C) > 0) {
        func_L01_005DBFA0(0, func_0045E850(0x255D), *(s32 *)(vars + 0x70));
    }
    func_L01_005DBFC8(0, func_0045E850(0x255C), *(s32 *)(vars + 0x78), *(s32 *)(vars + 0x74));
}
