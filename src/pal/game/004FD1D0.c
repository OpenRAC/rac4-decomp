#include "common.h"
typedef struct {
    s32 words[29];
} State;
extern State D_00329B00;
extern s32 D_0021F21C, D_0021DE40;
extern void func_00453E20(void *, s32, u32);
extern s32 func_004FD308(void);
void func_004FD1D0(void *state)
{
    func_00453E20(state, 0, sizeof(State));
    *(State *)state = D_00329B00;
    ((s32 *)state)[0] = D_0021F21C == 1;
    ((s32 *)state)[1] = D_0021DE40 / 50;
    ((s32 *)state)[7] = func_004FD308();
}
