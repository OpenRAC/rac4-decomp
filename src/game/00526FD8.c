#include "common.h"

typedef struct { u8 pad[0xA8]; u8 flags[0x100]; } Tab_00648A20;
extern Tab_00648A20 D_00171D38;
extern void func_00526F20(u8 *, u8 *);
extern void func_00526E80(u8 *, u8 *);

/* from rac3-decomp's func_L39_00648A20 */
void func_00526FD8(u8 *self, u8 *arg, u8 *third) {
    if (D_00171D38.flags[*(s32 *)(self + 0x2f10)]) {
        func_00526F20(self, third);
    } else {
        func_00526F20(self, arg);
    }
    func_00526E80(self, arg);
}
