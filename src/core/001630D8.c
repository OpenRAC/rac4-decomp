#include "common.h"

typedef struct { u8 b[8]; } Rec8;

extern Rec8 D_21BB90[];
extern Rec8 D_21C390[];
extern Rec8 D_21CB90[];
extern u8 D_21DC18[];

/* Appends the 8-byte record at arg1 to table arg0 (0, 1 or 2) and counts it in D_21DC18. */
s32 func_001630D8(s32 arg0, Rec8 *arg1) {
    switch (arg0) {
    case 0:
        D_21BB90[D_21DC18[0]] = *arg1;
        D_21DC18[0] += 1;
        return 8;
    case 1:
        D_21C390[D_21DC18[1]] = *arg1;
        D_21DC18[1] += 1;
        return 8;
    case 2:
        D_21CB90[D_21DC18[2]] = *arg1;
        D_21DC18[2] += 1;
        return 8;
    }
    return 0;
}
