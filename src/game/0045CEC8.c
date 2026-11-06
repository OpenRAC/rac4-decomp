#include "common.h"
extern s32 D_0021DE10;
typedef struct {
    s32 result, key;
} Pair;
extern Pair D_003DB148[];
s32 func_0045CEC8(s32 key)
{
    s32 i = 0;
    Pair *p;
    if (key == 0x2726) {
        if (D_0021DE10 == 14 || D_0021DE10 == 34)
            return 0x246A;
        return 0x2133;
    }
    if (key == 0x2727) {
        if (D_0021DE10 == 14 || D_0021DE10 == 34)
            return 0x246D;
        return 0x2130;
    }
    for (; D_003DB148[i].result != -1; i++)
        if (key == D_003DB148[i].key)
            return D_003DB148[i].result;
    return key;
}
