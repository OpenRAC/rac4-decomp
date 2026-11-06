#include "common.h"

typedef struct {
    s32 phase;
    u8 tail[0x70];
} State;
extern State D_0030B7F8[];
extern char D_0030B6F8[];
extern s32 D_00221980;
extern const char D_0021FA60[];
extern const char D_0021FA70[];
extern s32 func_00506BB8(void);
extern s32 func_004A2798(s32 *, s32);
extern s32 func_005062D0(s32, const char *);
extern char *func_0045E850(s32);
extern s32 func_0011D920(char *, const char *, ...);

void func_004C3C10(void)
{
    State *state = (State *)((u32)D_0030B7F8 + (u32)func_00506BB8() * 0x74);

    func_005062D0(func_004A2798(&D_00221980, 0x41), D_0030B6F8);
    if (state->phase == 2) {
        const char *format = D_0021FA60;
        const char *second;
        const char *first = func_0045E850(0x30D1);
        second = func_0045E850(0x30D2);
        func_0011D920(D_0030B6F8, format, first, second, func_0045E850(0x2350));
    } else {
        const char *format = D_0021FA70;
        const char *first = func_0045E850(0x234F);
        func_0011D920(D_0030B6F8, format, first, func_0045E850(0x2350));
    }
}
