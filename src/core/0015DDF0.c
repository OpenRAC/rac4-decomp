#include "common.h"

extern s32 D_2120F8[];
extern s32 func_01E9E138(s32 arg0, s32 arg1);
extern char func_0015DFD8[];
extern char func_0015E038[];
extern char func_0015E098[];
extern char func_0015E0F8[];
extern char func_0015E158[];
extern char func_0015E1B8[];
extern char func_0015E218[];
extern char func_0015E278[];
extern char func_0015E2D8[];
extern char func_0015E338[];
extern char func_0015E3B8[];
extern char func_0015E418[];
extern char func_0015E478[];
extern char func_0015E4D8[];
extern char func_0015E538[];
extern char func_0015E598[];
extern char func_0015E5F8[];
extern char func_0015E658[];
extern char func_0015E6B8[];

/* Registers the 19 callbacks of the table at D_2120F8 with func_01E9E138; 1 if any call fails, else the last call's result != 0. */
s32 func_0015DDF0(void)
{
    char *base;

    base = (char *)D_2120F8;
    if (func_01E9E138((s32)base, (s32)func_0015DFD8) != 0) {
        return 1;
    }
    if (func_01E9E138((s32)(base + 0x4), (s32)func_0015E038) != 0) {
        return 1;
    }
    if (func_01E9E138((s32)(base + 0x8), (s32)func_0015E098) != 0) {
        return 1;
    }
    if (func_01E9E138((s32)(base + 0xC), (s32)func_0015E0F8) != 0) {
        return 1;
    }
    if (func_01E9E138((s32)(base + 0x10), (s32)func_0015E158) != 0) {
        return 1;
    }
    if (func_01E9E138((s32)(base + 0x14), (s32)func_0015E1B8) != 0) {
        return 1;
    }
    if (func_01E9E138((s32)(base + 0x18), (s32)func_0015E218) != 0) {
        return 1;
    }
    if (func_01E9E138((s32)(base + 0x1C), (s32)func_0015E278) != 0) {
        return 1;
    }
    if (func_01E9E138((s32)(base + 0x20), (s32)func_0015E2D8) != 0) {
        return 1;
    }
    if (func_01E9E138((s32)(base + 0x24), (s32)func_0015E338) != 0) {
        return 1;
    }
    if (func_01E9E138((s32)(base + 0x28), (s32)func_0015E3B8) != 0) {
        return 1;
    }
    if (func_01E9E138((s32)(base + 0x2C), (s32)func_0015E418) != 0) {
        return 1;
    }
    if (func_01E9E138((s32)(base + 0x30), (s32)func_0015E478) != 0) {
        return 1;
    }
    if (func_01E9E138((s32)(base + 0x34), (s32)func_0015E4D8) != 0) {
        return 1;
    }
    if (func_01E9E138((s32)(base + 0x38), (s32)func_0015E538) != 0) {
        return 1;
    }
    if (func_01E9E138((s32)(base + 0x3C), (s32)func_0015E598) != 0) {
        return 1;
    }
    if (func_01E9E138((s32)(base + 0x40), (s32)func_0015E5F8) != 0) {
        return 1;
    }
    if (func_01E9E138((s32)(base + 0x44), (s32)func_0015E658) == 0) {
        return func_01E9E138((s32)(base + 0x48), (s32)func_0015E6B8) != 0;
    }
    return 1;
}
