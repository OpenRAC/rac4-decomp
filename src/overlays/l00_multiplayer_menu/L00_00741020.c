#include "common.h"

extern void func_L00_0069BED8(s32, f32, f32);
extern s32 func_L00_0069C340(s32 handle, float *a, float *b);

/* moves an object's handle by the offset between a point and its anchor */
void func_L00_00741020(u8 *arg0, f32 x, f32 y) {
    f32 v[4];

    func_L00_0069C340(*(s32 *)(arg0 + 0x240) | 0xA3, &v[0], &v[1]);
    x -= v[0];
    y -= v[1];
    func_L00_0069C340(*(s32 *)(arg0 + 0x240), &v[2], &v[3]);
    v[2] += x;
    v[3] += y;
    func_L00_0069BED8(*(s32 *)(arg0 + 0x240), v[2], v[3]);
}
