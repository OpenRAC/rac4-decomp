#include "common.h"

extern char *func_0011AFC8(char *, char *, s32);
extern char D_003F2290[];
void *D_00220A2C = 0;

/* Swaps the global owner for arg0, calling the old owner's hook and copying the new owner's value into D_003F2290. */
void *func_L00_0070A138(void *arg0) {
    void *temp;

    temp = D_00220A2C;
    if (temp != 0) {
        (*(void (**)(void *, char *))((u8 *)*(void **)((u8 *)temp + 0x58) + 0xE8))(temp, D_003F2290);
    }
    if (arg0 != 0) {
        func_0011AFC8(D_003F2290, (*(char *(**)(void *))((u8 *)*(void **)((u8 *)arg0 + 0x58) + 0xF4))(arg0), 0xC8);
        D_003F2290[0xC7] = 0;
    }
    D_00220A2C = arg0;
    return temp;
}
