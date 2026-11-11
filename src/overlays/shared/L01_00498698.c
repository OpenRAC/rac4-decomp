#include "common.h"

typedef struct { u8 pad[0x74]; u8 value; u8 pad75[0x24]; u8 enabled; } Inner;
typedef struct { u8 pad[0xAC]; Inner *inner; } Root;
typedef struct { u8 pad[0x14]; s32 value; } Object;

extern s32 D_0021DE10;
extern u8 D_001F87F0[];
s32 func_L00_00702608(s32, s32);
Object *func_006C1008(s32);

s32 func_L01_00498698(Root *root) {
    s32 i;
    Inner *inner = root->inner;
    Object *obj;

    if (inner->enabled == 0) return 0;
    inner->enabled = 0;
    if (inner->value == 5) return 1;
    i = 0;
    do {
        obj = func_006C1008(func_L00_00702608(D_0021DE10, i));
        if (obj->value == 0) {
            s32 row = (D_0021DE10 - 1) % 20;
            if ((s32)D_001F87F0[row * 0x304 + i * 0xC + 0xA] - 1 < inner->value) return 0;
        }
        i++;
    } while (i < 0x40);
    return 1;
}
