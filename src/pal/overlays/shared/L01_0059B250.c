#include "common.h"
s32 func_L01_0059B250(const u8 *object)
{
    switch (*(const s16 *)(object + 0xBC)) {
    case 0x2073:
    case 0x24AE:
    case 0x2639:
    case 0x263B:
        return 1;
    }
    return 0;
}
