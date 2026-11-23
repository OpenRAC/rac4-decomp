/* Not matching yet: PAL WIP; level_01 .text 0x0067CF48, 400B. Not part of the build. */
/*
 * No exact ordinary reconstruction of native metric f0->f2 copy and threshold/field register
 * lifetime found. Existing sourcegraphs keep metricf1 and omit that copy; adding a dummy explicit
 * copy or forcing registers/lifetime/types/flags is disallowed. This is a bounded source-family
 * result, not compiler-impossibility or permanent target ban.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 062493513404d0df125e8cabbba2e2ae11833b360b8f0bdbce8a2c2e4f0fbb55
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L01_0067CF48 nonmatching/pal/shared/func_L01_0067CF48.c --diff
 */
#include "common.h"

extern f32 D_00222C88;
extern f32 D_00222C8C;
extern s32 D_0021E8A4;
extern s32 D_0021E8A8;
extern f32 func_L01_0067CEA8(void *object);

s32 func_L01_0067CF48(void *object) {
    u8 *obj = object;
    u8 *probe;
    u8 *link;
    s32 blocked = 0;
    f32 metric;
    f32 field;
    s32 status;
    s32 mode;

    probe = *(u8 **)(obj + 0x2EF0);
    if (probe == NULL || probe[0x31] != 0) {
        blocked = 1;
    }
    link = *(u8 **)(obj + 0x2EF0);
    metric = D_00222C8C;
    if (link != NULL) {
        if (obj[0x266D] != 0) {
            *(f32 *)(obj + 0x2654) = 0.0f;
        } else {
            *(f32 *)(obj + 0x2654) = func_L01_0067CEA8(link);
        }
        metric = D_00222C8C;
    }

    status = 5;
    if (0.99f <= metric) {
        goto one;
    }
    if (0.99f <= D_00222C88) {
        return 1;
    }
    field = *(f32 *)(obj + 0x2654);
    if (!blocked && 5.0f < field) {
one:
        return 1;
    }
    if (0.93f <= metric) {
        status = 4;
    }
    if (0.98f <= metric) {
        status--;
    }
    mode = D_0021E8A4;
    if (mode == 1) {
        status--;
    }
    if (mode == 0) {
        if (D_0021E8A8 == 1) {
            status -= 2;
        }
    }
    if (10.0f <= field) {
        status--;
    }
    if (25.0f <= field) {
        status--;
    }
    return status > 0 ? status : 1;
}
