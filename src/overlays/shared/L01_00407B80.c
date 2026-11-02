#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x74];
    u16 f74;
};
/* Update the observed field through the documented pointer offsets. */

void func_L01_00407B80(Type1 *arg0) {
    arg0->f74 = (u16) (arg0->f74 | 3);
}
