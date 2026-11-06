#include "common.h"
typedef struct {
    s32 words[29];
} State;
extern State D_00329B00;
extern s32 D_0021F19C, D_0021DDB8;
extern void func_00453608(void *, s32, u32);
extern s32 func_004FC298(void);
void func_004FC160(void *state)
{
    func_00453608(state, 0, sizeof(State));
    *(State *)state = D_00329B00;
    ((s32 *)state)[0] = D_0021F19C == 1;
    ((s32 *)state)[1] = D_0021DDB8 / 60;
    ((s32 *)state)[7] = func_004FC298();
}
