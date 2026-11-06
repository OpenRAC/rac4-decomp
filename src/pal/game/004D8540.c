#include "common.h"
typedef struct {
    s32 phase, flags;
} State;
typedef struct {
    void (*callback)(s32);
} Hook;
extern u8 D_0031E898[];
extern s32 D_0021FCBC;
extern s32 func_00506BB8(void);
extern void func_0045E6A0(void), func_00502520(void *), func_004D8650(void), func_004D8AD8(void), func_004D8808(void);
extern s32 func_004A2468(void *);
extern const Hook *func_0046DD08(s32, s32, s32);

void func_004D8540(void *object)
{
    State *state = (State *)((u32)D_0031E898 + (u32)func_00506BB8() * 0x528);
    s32 phase = state->phase;
    const Hook *hook;
    switch (phase) {
    case 1:
        func_0045E6A0();
        func_00502520(object);
        break;
    case 0:
        state->phase = 2;
        break;
    case 2:
        func_004D8650();
        break;
    }
    if (state->flags & 1)
        func_004D8AD8();
    func_004A2468((u8 *)state + 0x4BC);
    if (state->flags & 2)
        func_004D8808();
    if (phase == 0) {
        hook = func_0046DD08(0x26CA, 0, 4);
        if (hook && hook->callback)
            hook->callback(D_0021FCBC);
    }
}
