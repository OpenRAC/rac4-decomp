#include "common.h"

extern s32 D_00223240;
extern s32 D_00223260;
extern void func_L00_00717C68(void);
extern void func_L00_00717E48();
extern void func_L00_00717EC8();

// Clears a slot and decrements the count.
void func_L00_00717D98(s32 arg0) {
    func_L00_00717E48(arg0);
    func_L00_00717C68();
    *(s32 *)((arg0 * 4) + (u8 *)&D_00223240) = -1;
    D_00223260 = D_00223260 - 1;
    func_L00_00717EC8(-1);
}
