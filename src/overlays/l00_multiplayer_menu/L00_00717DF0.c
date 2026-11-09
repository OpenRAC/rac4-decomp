#include "common.h"

void func_L00_00717C68();
void func_L00_00717E48(s32);
void func_L00_00717EC8();
extern s32 D_00223240;

void func_L00_00717DF0(s32 arg0, s32 arg1) {
    func_L00_00717E48(arg1);
    *(s32 *)((arg1 * 4) + (u8 *)&D_00223240) = arg0;
    func_L00_00717C68();
    func_L00_00717EC8();
}
