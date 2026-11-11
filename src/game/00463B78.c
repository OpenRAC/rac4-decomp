#include "common.h"

typedef struct {
    u8 p0[0x8C];
    u16 count;
    u8 p8E[0x12];
    u8 *source, *end;
    u8 pA8[0x14];
    u8 *buffer;
} State;
extern State D_00237000[];
typedef union {
    s32 word;
    u16 half;
} Counter;
extern Counter D_00266760[];
extern u32 func_00469C40(const void *, void *);
extern void func_00453808(void *, const void *, u32);
extern void func_004640A0(s32, void *, void *, s32, s32);
void func_00463B78(void)
{
    u32 size = func_00469C40(D_00237000[0].buffer, D_00237000[0].source);
    u8 *base = (u8 *)((u32)D_00237000[0].end - size);
    s32 *record;
    s32 first, before;
    func_00453808(base, D_00237000[0].source, size);
    D_00237000[0].buffer = base;
    D_00237000[0].end = base;
    record = (s32 *)base;
    first = *record++;
    before = D_00266760[0].word;
    while (first >= 0) {
        s32 offset = *record++;
        s32 other = record[0];
        void *optional = 0;
        record += 2;
        if (offset)
            optional = (void *)((u32)D_00237000[0].buffer + (u32)offset);
        func_004640A0(first, (void *)((u32)D_00237000[0].buffer + (u32)other), optional, 0, 1);
        first = *record++;
    }
    D_00237000[0].count = D_00266760[0].half - before;
}
