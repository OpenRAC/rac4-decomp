#include "common.h"
#include "pal/object_data.h"

extern s16 *D_L06_00288AA0[];
extern s32 D_00222694;
s32 D_L06_002226E0 = 0;
extern void func_00474368(u8 *, s32, s32);
extern void func_L06_00401EE0(void *);

/* State 0 arms the moby; state 1 walks its id list, then advances the state. */
void func_L06_004C9E88(u8 *moby) {
    u8 *self;
    s32 state;
    u8 *vars;
    s16 *list;
    s32 index;
    u32 object;

    self = moby;
    state = self[0x20];
    vars = (u8 *)((PalObject *)self)->data;
    if (state == 1) {
        goto state1;
    }
    if (state >= 2) {
        return;
    }
    if (state != 0) {
        return;
    }
    func_00474368(self, 1, -1);
    return;
state1:
    list = D_L06_00288AA0[*(s32 *)vars];
    for (;;) {
        index = *(s32 *)vars;
        if ((index & 0xFF) == 0xFF) {
            break;
        }
        if (D_L06_002226E0 < index) {
            break;
        }
        if (list == 0) {
            break;
        }
        if (list[-1] < 0 && list != D_L06_00288AA0[index]) {
            break;
        }
        object = (u32)D_00222694 + ((*(u16 *)list & 0x7FFF) << 8);
        if (object == 0) {
            break;
        }
        list += 1;
        func_L06_00401EE0((void *)object);
    }
    func_00474368(self, 2, -1);
}
