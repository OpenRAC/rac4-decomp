#include "common.h"

extern void func_01E9E710(void);
extern void func_001623A8(void);
extern void func_00162540(void);

void func_00162698(void *arg0) {
    s32 *p = (s32 *)arg0;

    func_01E9E710();
    p[0x1C/4] = 0;
    p[0x04/4] = 1;
    p[0x14/4] = 0x4000;
    p[0x0C/4] = 4;
    p[0x08/4] = 5;
    p[0x20/4] = 1;
    p[0x18/4] = 0x4000;
    p[0x40/4] = (s32)&func_001623A8;
    p[0x24/4] = 0x10;
    p[0x28/4] = 0x1F40;
    p[0x38/4] = (s32)&func_00162540;
    p[0x2C/4] = 1;
    p[0x30/4] = 0x10;
    p[0x34/4] = 0x1F40;
}
