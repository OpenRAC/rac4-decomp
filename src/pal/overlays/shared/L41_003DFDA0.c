#include "common.h"

typedef int u128 __attribute__((mode(TI)));
extern void func_0053DED0(s32 *, void *, s32);
extern void func_L41_003E0838();
extern void func_L41_005F7410(void *, void *, void *, s32, f32);
typedef struct { u8 pad0[0x70]; s32 f70[10]; s32 f98[10]; } Type1;
#include "pal/global_00222894.h"
extern u8 *D_00344C38[];

// Read a network message and update an object's per-slot timers.
void func_L41_003DFDA0(void *arg0, s32 *arg1) {
    s32 index;
    u128 data;
    f32 value;
    s32 flag;
    s32 slot;
    s32 other;
    Type1 *state;
    u32 kind;

    kind = *arg1 & 0xF;
    state = *(Type1 **)((u8 *)arg0 + 0xAC);
    if (kind < 10) {
        func_0053DED0(arg1, &index, 4);
        func_0053DED0(arg1, &data, 0x10);
        func_0053DED0(arg1, &value, 4);
        func_0053DED0(arg1, &flag, 4);
        func_0053DED0(arg1, &slot, 4);
        if (D_00344C38[index] != 0) {
            func_L41_005F7410(D_00344C38[index], &data, D_00222894 + (slot << 8), 0x34, value);
            D_00344C38[index][0x266E] = flag;
            state->f70[index] = 0x32;
            state->f98[index] = slot;
            func_L41_003E0838(arg0, D_00344C38[index]);
        }
    } else if (kind == 10) {
        func_0053DED0(arg1, &other, 4);
        state->f70[other] = -0x32;
    }
}
