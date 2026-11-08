#include "common.h"

typedef struct { u8 pad[0xA8]; u8 flags[0x100]; } Tab_005281D0;
extern Tab_005281D0 D_00171DB8;
extern void func_00528118(u8 *, u8 *);
extern void func_00528078(u8 *, u8 *);

/* PAL: from rac3-decomp's func_L39_00648A20 */
void func_005281D0(u8 *self, u8 *arg, u8 *third) {
    if (D_00171DB8.flags[*(s32 *)(self + 0x2f10)]) {
        func_00528118(self, third);
    } else {
        func_00528118(self, arg);
    }
    func_00528078(self, arg);
}
