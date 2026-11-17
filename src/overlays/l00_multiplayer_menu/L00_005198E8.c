#include "common.h"

extern s32 func_L00_00540220(void);
extern s32 func_L00_00540270(s32 arg0);
extern void func_00540298(void *);
extern void func_005402C0(void *);
extern void func_005402E8(void *);
extern void func_00540310(void *);
extern u8 func_L00_00519944[];
extern u8 func_L00_00519974[];
extern u8 func_L00_00529020[];
extern u8 func_L00_0052A46C[];
extern u8 func_L00_0052A758[];

/* Calls six helpers with the addresses of the named blocks (some offset), then returns 1. */
s32 func_L00_005198E8(void) {
    func_L00_00540220();
    func_L00_00540270((s32)(func_L00_00519974 + 4));
    func_00540298(func_L00_0052A46C + 4);
    func_005402C0(func_L00_0052A758);
    func_005402E8(func_L00_00529020 + 8);
    func_00540310(func_L00_00519944 + 4);
    return 1;
}
