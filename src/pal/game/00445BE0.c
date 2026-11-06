#include "common.h"

/* The entry path saves a word; the exit path restores its low halfword. */
typedef union SavedValue {
    s32 word;
    u16 half;
} SavedValue;

typedef struct Environment {
    u32 unknown0[3];
    u32 begin;
    u32 end;
} Environment;

typedef struct State {
    u32 begin;
    u32 end;
    u32 limit;
    u32 unknownC[2];
    u32 scratch;
    u32 value;
} State;

extern Environment D_0023AC00;
extern State D_00235A40;
extern u32 D_002212CC;
extern u32 D_00221F28;
extern u32 D_0021EE68;
extern u32 D_0021DAB4;
extern s16 D_00206A18[];
extern f32 D_002212D0;
SavedValue D_0021EBAC = {-1};
extern void func_004E8758(u32 mask);
extern s32 func_00138D70(s32 mode);
extern void func_004E8560(void);
extern void func_004E5B78(s32 mode);

void func_00445B08(void)
{
    func_004E8758(1);
    func_00138D70(0);
    ++D_002212CC;
    D_00235A40.scratch = D_00221F28 - 0x60000U;
    D_00235A40.begin = D_0023AC00.begin + 0x60000U;
    D_00235A40.end = D_0023AC00.end + 0x60000U;
    D_00235A40.limit = D_00235A40.begin + 0xD0800U;
    D_0021EE68 = 0x2000;
    D_00221F28 = 0x60000;
    func_004E8560();
    func_004E5B78(1);
    D_00235A40.value = D_0021DAB4;
    D_002212D0 = 1.0f;
    D_0021EBAC.word = D_00206A18[0];
}

extern u32 D_00235A58[];
extern void func_004E8448(void);
extern void func_00449B28(s32 count, s32 flag);

void func_00445BE0(void)
{
    func_004E8758(1);
    func_004E8448();
    func_004E8560();
    D_002212D0 = 0.0f;
    D_0021DAB4 = D_00235A58[0];
    func_00449B28(30, 0);
    D_00206A18[0] = D_0021EBAC.half;
}
