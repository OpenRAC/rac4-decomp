#include "common.h"
typedef struct {
    u8 pad00[0xC];
    s32 first, second;
    u8 pad14[8];
    s32 third, fourth, percentage;
} Record;
typedef struct {
    s32 first, second, third, percentage, fourth;
    u8 enabled;
} Output;
extern s32 func_0054C0A8(s32 item, s32 index);
extern const Record *func_0054BF18(s32 record);
extern u8 D_00171C28[];
/* Both calls in the only resident caller, 4CF500, pass its loop index:
 * s5 starts at0 (4CF5D8), increments after the second call (4CF740),
 * and continues only below15 (4CF780..4CF7A8).  Thus the bit shift below
 * is the original index0..14 after subtracting the encoded group. */
void func_004FD380(s32 item, s32 index, Output *output)
{
    const Record *record;
    s32 group;
    if (index < 30)
        index = (s32)((u32)(((s32)((u32)item - 1) % 20) * 30) + (u32)index);
    record = func_0054BF18(func_0054C0A8(item, index));
    group = (s32)((u32)item - 1) % 20;
    output->first = record->first;
    output->second = record->second;
    output->third = record->third;
    output->percentage = (s32)((f32)record->percentage * 0.01f) * 100;
    output->fourth = record->fourth;
    output->enabled = (*(s32 *)((u32)D_00171C28 + ((u32)group << 2)) >> ((u32)index - (u32)(group * 30))) & 1;
}
