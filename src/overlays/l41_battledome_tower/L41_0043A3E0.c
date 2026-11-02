#include "common.h"

extern void *func_L01_006B4FC0(void *, s32, s32, s32);
extern void func_00611808(void *, void *, s32);

/* Builds a helper object from arg0 and hands it a stack copy of arg1. */
void func_L41_0043A3E0(void *arg0, s32 arg1) {
    void *p = func_L01_006B4FC0(arg0, 1, 0, 0xFA);
    s32 v = arg1;
    func_00611808(p, &v, 4);
}
