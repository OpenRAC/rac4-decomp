/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u16 id; u16 f2; s32 f4; s32 f8; s32 fC; } Ent;
typedef struct { s32 f0; Ent e[16]; u32 count; } Tab;
extern Tab D_001B6898;
extern void *func_0011A518(void *, s32, u32);
s32 func_01EC24C0(u16 id) {
    u32 i;
    if (id == 0) {
        return 2;
    }
    for (i = 0; i < 16; i++) {
        if (id == D_001B6898.e[i].id) {
            func_0011A518(&D_001B6898.e[i], 0, sizeof(Ent));
            D_001B6898.count--;
            return 0;
        }
    }
    return 2;
}
