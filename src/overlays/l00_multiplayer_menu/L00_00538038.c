/* cflags: @ee29 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    char _p4[0xC];
    s32 f10;
};

s32 func_004FAD28(void *);

void func_L00_00538038(Type1 *arg0) {
    if (arg0 == NULL) return;
    if (arg0->f0 != 0 && !(arg0->f10 & 2)) {
        func_004FAD28((void *)arg0->f0);
    }
    arg0->f10 |= 0x8000;
    if (arg0->f10 & 1) func_004FAD28(arg0);
}
