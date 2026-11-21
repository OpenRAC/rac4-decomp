#include "common.h"

extern char *func_0011AFC8(char *, char *, s32);
extern s32 func_00161128(void);
extern char D_00172160[];
typedef struct { char b[0x100]; } Blk256;

// Copies the request block at arg0 into the state at D_00172160.
void func_0015B670(char *arg0) {
    char *p = D_00172160;
    char *tb;

    *(s32 *)(p + 0x490) = func_00161128();
    *(s32 *)(p + 0x494) = *(s32 *)(arg0 + 0x30);
    func_0011AFC8(p + 0x498, arg0 + 0x134, 0x40);
    *(Blk256 *)(p + 0x4D8) = *(Blk256 *)(arg0 + 0x34);
    tb = D_00172160;
    *(s32 *)(tb + 0x5D8) = *(s32 *)(arg0 + 0x20);
    *(s32 *)(tb + 0x5DC) = *(s32 *)(arg0 + 0x24);
    *(s32 *)(tb + 0x5E0) = *(s32 *)(arg0 + 0x28);
    *(s32 *)(tb + 0x5E4) = *(s32 *)(arg0 + 0x2C);
    *(s32 *)(tb + 0x5E8) = *(s32 *)(arg0 + 0x174);
    *(s32 *)(tb + 0x5EC) = *(s32 *)(arg0 + 0x178);
    *(s32 *)(tb + 0x5F0) = *(s32 *)(arg0 + 0x17C);
    *(s32 *)(tb + 0x5F4) = *(s32 *)(arg0 + 0x180);
    *(s32 *)(tb + 0x5F8) = *(s32 *)(arg0 + 0x184);
    *(s32 *)(tb + 0x5FC) = *(s32 *)(arg0 + 0x188);
    *(s32 *)(tb + 0x600) = *(s32 *)(arg0 + 0x18C);
    *(s32 *)(tb + 0x604) = *(s32 *)(arg0 + 0x190);
    *(s32 *)(tb + 0x608) = *(s32 *)(arg0 + 0x194);
    *(s32 *)(tb + 0x60C) = *(s32 *)(arg0 + 0x198);
}
