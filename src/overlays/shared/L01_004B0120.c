#include "common.h"
typedef struct O { u8 pad[0xBC]; s16 id; } O;
s32 func_L01_004B0120(O *o) {
    switch (o->id) {
    case 0x1087: return 3;
    case 0x1864: return 1;
    case 0x1096: return 6;
    default: return 0;
    }
}
