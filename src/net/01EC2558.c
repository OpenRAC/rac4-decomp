/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u16 id; u16 f2; s32 f4; s32 f8; s32 fC; } Ent;
typedef struct { s32 f0; Ent e[16]; u32 count; } Tab;
extern Tab D_001B6898;
s32 func_01EC2558(u16 id, Ent **out) {
    u32 i;
    u32 free = 16;
    if (out == 0) {
        return 2;
    }
    *out = 0;

    for (i = 0; i < 16; i++) {
        if (id != 0 && id == D_001B6898.e[i].id) {
            *out = &D_001B6898.e[i];
            return 0;
        }
        if (D_001B6898.e[i].id != 0 && free == 16) {
            free = i;
        }
    }
    if (*out == 0 && free != 16) {
        *out = &D_001B6898.e[free];
    }
    return 0;
}
