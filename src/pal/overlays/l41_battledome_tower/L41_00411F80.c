/* cflags: -O2 -G8 -fopt-stack -mno-check-zero-division */
/* C adapted from rac3-decomp func_L40_004224F8 (commit cd0e7c20fd8a). */
#include "common.h"

/* Test membership of the signed halfword at0xBC in this numeric set. */
s32 func_L41_00411F80(u8 *a0) {
    switch (*(s16 *)(a0 + 188)) {
    case 6842:
    case 6843:
    case 6844:
    case 6845:
    case 6846:
    case 6848:
    case 6849:
        return 1;
    }
    return 0;
}
