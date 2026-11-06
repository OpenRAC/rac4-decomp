#include "common.h"
typedef struct {
    char pad[0xE4];
    s32 active[16];
    void *pending[16];
} Table;
extern s32 func_00502510(void *);
s32 func_005014E0(Table **a, void *b)
{
    s32 result = -1;
    s32 i;
    if (!func_00502510(b)) {
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
