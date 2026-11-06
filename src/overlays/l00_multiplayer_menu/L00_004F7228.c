#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x14];
    s32 f14;
};
/* Update the observed field through the documented pointer offsets. */

void func_L00_004F7228(Type1 *arg0) {
    arg0->f14 = (s32) (arg0->f14 & ~0xF);
}
