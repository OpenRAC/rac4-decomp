#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8[4];
} Type1;

extern Type1 D_1E0C70[];
extern s32 func_L00_0073A230(void *, s32);

// Rebuild the list of menu entries at +0xE0C that pass func_L00_0073A230.
void func_L00_00739E88(void *arg0) {
    u8 *p = (u8 *)arg0;
    s32 **ptrs;
    s32 *ids;
    s32 i;
    if (*(u8 *)(p + 0xE04) != 0) {
        if (*(u8 *)(p + 0x26C) != 0) {
            *(s32 *)(p + 0xE08) = 0;
        } else {
            *(u8 *)(p + 0xE04) = 0;
            *(s32 *)(p + 0xE08) = 0;
            ptrs = (s32 **)(p + 0xE38);
            ids = (s32 *)(p + 0xE0C);
            for (i = 0; i < 11; i++) {
                if (D_1E0C70[i].f0 >= 0 && func_L00_0073A230(arg0, D_1E0C70[i].f0) == 0) {
                    *(s32 **)((u32)ptrs + (*(s32 *)(p + 0xE08) << 2)) = D_1E0C70[i].f8;
                    *(s32 *)((u32)ids + (*(s32 *)(p + 0xE08) << 2)) = D_1E0C70[i].f0;
                    *(s32 *)(p + 0xE08) = *(s32 *)(p + 0xE08) + 1;
                }
            }
        }
    }
}
