/* cflags: @ee29 -O2 -G8 -Wuninitialized */
#include "common.h"
typedef struct Type1 {
    int f0, f4, f8, fc, f10;
} Type1;
extern Type1 D_004A1930;
extern int D_004A1944[];
extern Type1 *func_L00_00525B70(int);
/* Refresh and return the cached twenty-byte value. */
Type1 *func_L00_00520E90(void) {
    if (D_004A1944[0]) {
        D_004A1930 = *func_L00_00525B70(0);
        D_004A1944[0] = 0;
    }
    return &D_004A1930;
}
