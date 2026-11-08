/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x50];
    s32 f50;
};

void func_004FAD28(void *);
void func_L00_00538038(s32);

void func_L00_00547500(Type1 *arg0) {
    func_L00_00538038((void *)((u8 *)arg0 + 0xC));
    func_L00_00538038((void *)((u8 *)arg0 + 0x20));
    func_L00_00538038((void *)((u8 *)arg0 + 0x34));
    if (arg0->f50 & 1) {
        func_004FAD28(arg0);
    }
}
