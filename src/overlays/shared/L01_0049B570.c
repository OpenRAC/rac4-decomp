#include "common.h"
extern void func_0046BDD0(void *);
extern void func_004493E8(void *, void (*)(void *), void *);
extern s32 func_004E2118(s32, s32, s32, s32, s32);
extern void func_L01_0049B660(void *);
extern s32 D_00222A9C;
extern s32 D_0021DE10;
extern s32 D_0021DDB8;
void func_L01_0049B570(u8 *obj) {
    u8 *t = *(u8 **)(obj + 0xB8);
    s32 s;
    if (t == 0 || t[0x20] == 0xFE || t[0x20] == 0xFD || (obj[0x20] == 1 && !(t[0xBE] & 4))) {
        func_0046BDD0(obj);
        return;
    }
    func_004493E8(&D_00222A9C, func_L01_0049B660, obj);
    s = D_0021DE10;
    if ((s == 10 || s == 30) && D_0021DDB8 % 60 == 41) {
        func_004E2118(1, 0, (s32)obj, (s32)(obj + 0x10), 0x24EC);
    }
    if ((*(u8 **)(obj + 0xB8))[0xBE] & 4) obj[0x20] = 1;
}
