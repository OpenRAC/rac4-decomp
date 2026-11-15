#include "common.h"

extern s32 D_0039D230[];

s32 func_L01_00480328(s32 index) {
    s32 address;
    u8 kind;

    address = D_0039D230[index];
    if (address == 0) {
        goto accepted;
    }
    kind = *(u8 *)((u8 *)address + 0x20);
    if (kind == 0xFE) {
        goto accepted;
    }
    if (kind == 0xFD) {
        goto accepted_kind;
    }
    goto check_class;
accepted_kind:
accepted:
    return 1;
check_class:
    return *(s16 *)(address + 0xBC) != 0x20AB;
}
