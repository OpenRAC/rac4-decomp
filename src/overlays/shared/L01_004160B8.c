#include "common.h"

extern void func_00416028(void *a, void *b, void *c);
char D_00221030[8] = {0};
char D_00221038[8] = {0};

// Calls func_00416028 three times on the sub-object's field at 0xF0.
void func_L01_004160B8(void *arg0) {
    u8 *sub = *(u8 **)((u8 *)arg0 + 0xAC);
    s32 i = 2;
    do {
        func_00416028(sub + 0xF0, D_00221030, D_00221038);
        i--;
    } while (i >= 0);
}
