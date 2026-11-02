#include "common.h"
typedef struct __attribute__((packed)) { unsigned char bytes[32]; } Block;
typedef struct { char pad[0x1c0]; char flag; char pad2[3]; Block block; } Target;
typedef struct { char pad[0x5c]; Target *target; } Context;
extern Context *D_002233A4;
/* Clear the flag and copy the block. */
void func_L00_00776E88(Block *source) {
    Target *target = D_002233A4->target;
    target->flag = 0;
    target->block = *source;
}
