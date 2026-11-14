#include "common.h"

extern s32 func_L02_004C59E8(void *actor);
extern void func_L01_006B1D68(s32, void *, s32, void *);
extern void func_L02_004C9E30(void *);
extern void func_L02_004CA0E8(void *);
extern void func_L02_004CA368(void *);
extern void func_L02_004CAF10(void *, void *);
extern u8 D_003A5E30[];

// Runs the per-frame update steps for an actor, with one optional step gated on its state byte.
void func_L02_004CB1E0(void *arg0)
{
    s32 temp_s2;
    u8 *temp_s1;

    temp_s1 = *(u8 **)((u8 *)arg0 + 0xAC);
    temp_s2 = *(s32 *)(temp_s1 + 0x170);
    if (func_L02_004C59E8(arg0) != 0) {
        func_L02_004CAF10(arg0, temp_s1);
    }
    if (*(u8 *)((u8 *)arg0 + 0x67) == 9) {
        func_L01_006B1D68(temp_s2, arg0, 5, D_003A5E30);
    }
    func_L02_004C9E30(arg0);
    func_L02_004CA0E8(arg0);
    func_L02_004CA368(arg0);
}
