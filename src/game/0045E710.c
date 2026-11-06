#include "common.h"

typedef struct {
    s16 current;
    u8 pad02[2];
    u16 remaining;
} State;

extern State D_0023F2A8[];

extern u32 func_0045E748(void);

void func_0045E710(void)
{
    D_0023F2A8[0].current = func_0045E748();
    D_0023F2A8[0].remaining--;
}
