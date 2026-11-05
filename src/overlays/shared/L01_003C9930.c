#include "common.h"

extern void func_00585D88(void *);
extern s32 func_00653498(void);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern s32 D_0021EBD8;
extern s32 D_0021DE10;
extern u8 *D_00222D14;
extern u32 D_171C08[];
extern u8 D_1F87F0[];

s32 func_L01_003C9930(u8 *object) {
    u8 *data;
    s32 id;
    if (object[0x20] != 0) return 0;
    data = *(u8 **)(object + 0xAC);
    object[0x30] = 0xFF;
    id = *(s32 *)(data + 0x6C);
    if ((D_171C08[(u32)id >> 5] & (1 << (id & 0x1F))) && data[0x71] == 0
        && (data[0x7C] == 0
            || D_1F87F0[D_0021EBD8 * 0xC + ((D_0021DE10 - 1) % 20) * 0x304 + 9] == 0)) {
        data[0x7F] = 1;
        data[0x7E] = 1;
        func_L01_00591BD8(object, 3, -1);
        return 1;
    }
    if (*(s32 *)(data + 0x78) != -1) {
        *(u8 **)(data + 0x84) = D_00222D14 + (*(s32 *)(data + 0x78) << 8);
    }
    if (*(s32 *)(data + 0x88) == -1) {
        func_L01_00591BD8(object, 1, -1);
        return 1;
    }
    if (func_00653498() == *(s32 *)(data + 0x88)) {
        func_00585D88(object);
    }
    func_L01_00591BD8(object, 1, -1);
    return 1;
}
