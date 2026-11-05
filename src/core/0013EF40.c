/* cflags: @ee29 -O2 -G0 */
#include "common.h"
extern s64 func_0013EC48(void *);
extern void func_0013EFD8(void);
typedef struct { u8 pad0[0x828]; s32 f828; s32 f82C; s32 f830[6]; s32 f848; s32 f84C; } Type1;
void func_0013EF40(Type1 *arg0, s32 arg1) {
    s32 value;
    func_0013EFD8();
    value = arg1 | 0x40000000;
    *(volatile s32 *)0x10002000 = value;
    arg0->f82C = value & 0xF0000000;
    if (arg0->f82C == 0x20000000 || arg0->f82C == 0x30000000 || arg0->f82C == 0x40000000) arg0->f828 = 0;
    else arg0->f828 = 1;
    arg0->f848 = func_0013EC48(arg0);
    arg0->f84C = 0x20;
}
