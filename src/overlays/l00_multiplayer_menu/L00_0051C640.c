#include "common.h"

extern s32 func_0011A2DC();
extern s32 func_0011A8A0(void *, const u8 *);

/* compares two tagged records: tag first, then the payload by tag */
s32 func_L00_0051C640(s32 *arg0, s32 *arg1) {
    s32 r;
    s32 *pa;
    s32 *pb;

    r = arg0[0] - arg1[0];
    if (r != 0) {
        return r;
    }
    pa = (s32 *)arg0[1];
    pb = (s32 *)arg1[1];
    switch (arg0[0]) {
    case 0:
        r = pa[3] - pb[3];
        if (r != 0) {
            return r;
        }
        return func_0011A2DC(pa[4], pb[4], pa[3]);
    case 1:
        if (pa[0] == 0) {
            return -1;
        }
        if (pb[0] == 0) {
            return 1;
        }
        return func_0011A8A0((void *)pa[0], (u8 *)pb[0]);
    case 2:
        if (pa[1] == 0) {
            return -1;
        }
        if (pb[1] == 0) {
            return 1;
        }
        return func_0011A8A0((void *)pa[1], (u8 *)pb[1]);
    case 3:
        return pa[2] - pb[2];
    }
    return 1;
}
