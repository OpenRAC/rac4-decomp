#include "common.h"
extern s32 D_0021DE98;
typedef struct {
    s32 result, key;
} Pair;
extern Pair D_003DB188[];
s32 func_0045D6C0(s32 key)
{
    s32 i = 0;
    Pair *p;
    if (key == 0x2726) {
        if (D_0021DE98 == 14 || D_0021DE98 == 34)
            return 0x246A;
        return 0x2133;
    }
    if (key == 0x2727) {
        if (D_0021DE98 == 14 || D_0021DE98 == 34)
            return 0x246D;
        return 0x2130;
    }
    for (; D_003DB188[i].result != -1; i++)
        if (key == D_003DB188[i].key)
            return D_003DB188[i].result;
    return key;
}
