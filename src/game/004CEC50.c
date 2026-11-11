#include "common.h"

extern s32 func_0045E038(s32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_004CEEF8(void *arg0);
extern void func_00504F68(s32, s32);
extern s32 func_00505238(u32, s32);
extern void func_00505328(s32, s32);
extern s32 func_005054F8(u32 id, s32 amount);

/* Refreshes a menu entry's labels and colour from its item record. */
void func_004CEC50(u8 *arg0, u8 *arg1, s32 arg2)
{
    s32 *list;
    u8 *item;
    s32 id;

    list = (s32 *)(arg1 + 4);
    item = *(u8 **)(arg1 + 8);
    id = func_004A1A60(list, 2);
    func_00505238(id, func_0045E038(*(s32 *)(item + 4)));
    if (item[0xC] != 0) {
        func_00504F68(func_004A1A60(list, 3), 1);
        func_005054F8(func_004A1A60(list, 3), 0x754A);
    } else {
        func_00504F68(func_004A1A60(list, 3), 0);
    }
    if (arg2 == *(s32 *)(arg0 + 0x54)) {
        func_00505328(func_004A1A60((s32 *)(arg1 + 4), 2), 0x80D0D0D0);
    } else {
        id = func_004A1A60((s32 *)(arg1 + 4), 2);
        func_00505328(id, func_004CEEF8(item));
    }
}
