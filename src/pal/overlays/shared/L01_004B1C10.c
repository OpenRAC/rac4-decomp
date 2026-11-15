/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
s32 func_L01_004B1C10(void *arg0) {
    s16 value = *(s16 *)((u8 *)arg0 + 0xBC);
    switch (value) {
    case 0x1087: return 3;
    case 0x1864: return 1;
    case 0x1096: return 6;
    }
    return 0;
}
