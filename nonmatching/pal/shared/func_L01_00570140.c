/* Not matching yet: PAL WIP; level_01 .text 0x00570140, 192B. Not part of the build. */
/*
 * Every current difference is secondFPgroup+5C..78: native loadswidthnode/root
 * thenpositionnode/root andADDwidths beforeSUB/ABSdistance. Bestemitted group stilluses other
 * order/registerdataflow. Prologue/frame/guards/firstFPpredicate/likelylink/call/returntail match.
 * No exact native-FP/readsequencecertificate or all-placementmatch asserted.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: f970436a0234a57e3f194e8c8518e6d4daa4c441229cd1d0bbb5fc3e0493b88f
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L01_00570140 nonmatching/pal/shared/func_L01_00570140.c --diff
 */
#include "common.h"
extern f32 fabsf(f32);
extern s32 func_L01_0056E308(void *node);

s32 func_L01_00570140(void *object)
{
    u8 *root = object;
    u8 *node;
    f32 threshold;

    if (root == 0)
        return 0;
    node = *(u8 **)(root + 0x1AC);
    if (node == 0)
        return 1;
    threshold = 0.5f;
    do {
        f32 nodeDepth = *(f32 *)(node + 0x1BC);
        f32 rootDepth = *(f32 *)(root + 0x1BC);
        f32 distance = fabsf(nodeDepth - rootDepth);

        if (distance < threshold) {
        } else {
            f32 nodeWidth = *(f32 *)(node + 0x1C4);
            f32 rootWidth = *(f32 *)(root + 0x1C4);
            f32 nodePosition = *(f32 *)(node + 0x1C0);
            f32 rootPosition = *(f32 *)(root + 0x1C0);
            f32 widths = nodeWidth + rootWidth;
            distance = fabsf(nodePosition - rootPosition);

            if (widths < distance) {
            } else if (func_L01_0056E308(node) == 0) {
                return 0;
            }
        }
        node = *(u8 **)(node + 0x1AC);
    } while (node != 0);
    return 1;
}
