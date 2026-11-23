/* Not matching yet: PAL WIP; level_00 .text 0x005C2FE0, 132B. Not part of the build. */
/*
 * Native early pool return and bound-result control recovered. Symbol-plus-field address folding
 * remains different in the132B body; no masked or byte-exact acceptance.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 933dc0c2d6874bdddd57b74eba32405f43306c97b258fa7b5d1d609ee71563f6
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_005C2FE0 nonmatching/pal/shared/func_L00_005C2FE0.c --diff
 */
#include "common.h"

typedef struct {
    u8 pad[80];
    u8 *p50;
    u8 pad2[1036];
} Entry_3E6C58;
extern Entry_3E6C58 D_0022CB80[];

/* Return the active player's scale or the linked object's constant scale. */
f32 func_L00_005C2FE0(void *object) {
    u8 *context;
    u8 *payload;
    f32 result;

    context = *(u8 **)((u8 *)object + 0x130);
    if (context != NULL) {
        if (*(u8 *)(context + 0x266D) != 0) {
            u32 offset = (u32)*(s32 *)((u8 *)object + 0x12C) * 0x470u;
            return *(f32 *)((u8 *)D_0022CB80 + offset + 0x434);
        }
        payload = *(u8 **)(context + 0x2EF4);
        if (payload != NULL) {
            result = 1.5184364f;
            if (*(s16 *)(*(u8 **)(payload + 0x2B0) + 0xBC) != 0x2054) {
                result = 1.1100293f;
            }
            return result;
        }
        return 1.1100293f;
    }
    return 1.1100293f;
}
