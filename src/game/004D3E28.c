#include "common.h"

extern void func_004D3AE0(void);
extern void func_004D3A48(void);
extern void func_004D3C68(void);
extern void func_004D3B78(void);
extern void func_004D3D00(void);
extern void func_004D3DC0(void);
extern void func_004D39A8(void);
extern void func_004D3908(void);
extern void func_0047F768(s32, s32);
s32 D_0021FB80 = 0;

/* from rac3-decomp's func_003B3910 */
void func_004D3E28(void) {
    switch (D_0021FB80) {
    case 1:
        func_004D3AE0();
        break;
    case 2:
        func_004D3A48();
        break;
    case 3:
        func_004D3C68();
        break;
    case 7:
        func_004D3B78();
        break;
    case 8:
        func_004D3D00();
        break;
    case 5:
        func_004D3DC0();
        break;
    case 4:
        func_004D39A8();
        break;
    case 6:
        func_004D3908();
        break;
    case 0:
    default:
        func_0047F768(0, 0);
        break;
    }
}
