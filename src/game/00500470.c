#include "common.h"
typedef struct {
    char pad[0xE4];
    s32 active[16];
    void *pending[16];
} Table;
s32 func_005014A0(s32 *arg0);
s32 func_00500470(Table **a, void *b)
{
    s32 result = -1;
    s32 i;
    if (!func_005014A0(b)) {
        for (i = 0; i < 16; i++) {
            if (!(*a)->active[i] && !(*a)->pending[i]) {
                (*a)->pending[i] = b;
                result = i;
                break;
            }
        }
    }
    return result;
}
