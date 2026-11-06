#include "common.h"

typedef struct {
    u8 pad[0x25CC];
    s32 f25CC;
} Type1;

/* Whether the word at +0x25CC is 0x31 or 0x98. */
s32 func_L00_006F3930(Type1 *o) {
    s32 k = o->f25CC;
    if (k == 0x31 || k == 0x98) {
        return 1;
    }
    return 0;
}
