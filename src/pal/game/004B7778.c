#include "common.h"

typedef s32 (*Callback)(s32);

typedef struct {
    u8 unknown0[0x10];
    s32 value;
    u8 tail[0x1E4];
} State;
extern State D_003099F0[];
extern void func_004A0F28(s32, s32);
extern void func_004B6CE8(s32);
extern char *func_0045E850(s32);
extern void func_004B6D08(s32, const char *, Callback, s32);
extern void func_004B6D60(s32, Callback, const char *);
extern s32 func_004B8128(s32);
extern s32 func_004B8230(s32);
extern s32 func_004B7B98(s32);

void func_004B7778(s32 index)
{
    func_004A0F28(index, D_003099F0[index].value);
    func_004B6CE8(index);
    func_004B6D08(index, func_0045E850(0x1CF), func_004B8128, 1);
    func_004B6D08(index, func_0045E850(0x2387), func_004B8230, 1);
    func_004B6D08(index, func_0045E850(0x362D), func_004B7B98, 1);
    func_004B6D60(index, func_004B7B98, func_0045E850(0x106));
}
