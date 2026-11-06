#include "common.h"

extern void func_00438CD0(u8 *arg0);
extern void func_00438F58(s32 arg0, void *arg1);
extern void func_0045CA60(s32 arg0, s32 arg1, s32 arg2);
extern void func_0045CC28(void);
extern void func_00490400(s32);
extern void *func_00510BE8(s32 arg0);
extern u8 D_00172435[];
extern s32 *D_0021DDA4;
extern s32 D_0021DDAC;
extern s32 D_0021DE80;

void func_004B7A68(s32 arg0)
{
    s32 i;
    u8 *p;

    if (arg0 == 0)
        return;
    if (D_00172435[0] != 0) {
        D_0021DE80 = 1;
    } else {
        D_0021DE80 = 0;
    }
    for (i = 0; i < *D_0021DDA4; i++) {
        p = func_00510BE8(i);
        if (p != NULL) {
            if (*(u8 **)(p + 0x2F00) != NULL) {
                func_00438F58(0, *(u8 **)(p + 0x2F00));
                (*(u8 **)(p + 0x2F00))[0x188] = 0;
                (*(u8 **)(p + 0x2F00))[0x189] = 0;
                func_00490400(*(s32 *)(p + 0x2F00));
            }
            func_00438CD0(*(u8 **)(p + 0x2F00));
        }
    }
    D_0021DDAC = *D_0021DDA4;
    *D_0021DDA4 = 1;
    func_0045CC28();
    func_0045CA60(0, 1, -1);
}
