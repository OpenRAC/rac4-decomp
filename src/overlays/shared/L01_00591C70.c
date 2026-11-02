#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x67];
    s8 f67;
    char _p68[0x56];
    u8 fBE;
};
/* Store the byte argument and clear the 0x20 bit in a separate byte field. */

void func_L01_00591C70(Type1 *arg0, s8 arg1) {
    arg0->f67 = arg1;
    arg0->fBE = (u8) (arg0->fBE & 0xDF);
}
