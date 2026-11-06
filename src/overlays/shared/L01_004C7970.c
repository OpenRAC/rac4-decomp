#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x6A];
    u16 f6A;
};
/* Update the observed field through the documented pointer offsets. */

void func_L01_004C7970(Type1 *arg0) {
    arg0->f6A = (u16) (arg0->f6A + 1);
}
