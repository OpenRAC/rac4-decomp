#include "common.h"

/* Builds a four-byte block on the stack, passes it as the fourth argument to func_001593C8, then calls func_00159128, func_00157F98 and func_00159488(0). */
extern u8 D_0021DD84;
extern void func_00159128(void);
extern void func_00157F98(void);
extern s32 func_00159488(s32 arg0);
extern void func_001593C8(s32 arg0, s32 arg1, s32 arg2, void *arg3);

void func_00159A00(s32 arg0, s32 arg1, s32 arg2) {
    u8 buf[4];

    buf[0] = 0x20;
    buf[1] = D_0021DD84;
    buf[2] = 0;
    buf[3] = 0;
    func_001593C8(arg0, arg1, arg2, buf);
    func_00159128();
    func_00157F98();
    func_00159488(0);
}
