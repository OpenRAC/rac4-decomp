/* Reference: OpenRAC/rac3-decomp@cd0e7c20fd8a93116566ba2e024fa2f3536bd30c
 * src/levels/shared/L01_004463D0.c func_L01_004463F8.
 * Independently reconstructed from RAC4 PAL retail. */
#include "common.h"

typedef struct {
    f32 x, y, z, w;
} Vector;
s32 func_004749A0(const Vector *point, const Vector *vertices, s32 count)
{
    s32 i;
    s32 next = 0;
    s32 inside = 0;
    for (i = 0; i < count; i++) {
        next++;
        if (next == count)
            next = 0;
        if ((vertices[i].y < point->y && point->y <= vertices[next].y) ||
            (vertices[next].y < point->y && point->y <= vertices[i].y)) {
            if (vertices[i].x + (point->y - vertices[i].y) /
                                    (vertices[next].y - vertices[i].y) *
                                    (vertices[next].x - vertices[i].x) <
                point->x) {
                inside = !inside;
            }
        }
    }
    return inside;
}
