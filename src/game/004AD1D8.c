#include "common.h"

typedef struct {
    s16 id;
    u8 unknown2[0x12];
    u32 value;
    u8 tail[4];
} Record;

typedef struct {
    u8 unknown0[0x158];
    s32 selected;
    u8 tail[0x14];
} State;

typedef struct {
    s32 count;
} Count;

extern u8 D_00308B60[];
extern State D_00308B80[];
extern Record D_00308460[64];
extern Count *D_0021DDA4;
extern void func_00453608(void *, s32, u32);
extern void *func_004A2A48(s32);
extern s32 func_004A2D90(void *, s32, s32);
extern void *func_004964C8(void);

void func_004AD1D8(void)
{
    Record *record;
    s32 i;

    func_00453608(D_00308B60, 0, 0x20);
    func_00453608(D_00308B80, 0, 0x5C0);
    record = D_00308460;
    do {
        record->id = -1;
        record->value = 0;
        record++;
    } while ((s32)record < (s32)(D_00308460 + 64));
    for (i = 0; i < D_0021DDA4->count; i++) {
        D_00308B80[i].selected = -1;
    }
    func_004A2D90(func_004A2A48(0), 0, 0);
    func_00453608(func_004964C8(), 0, 0x20);
}
