/* cflags: -mno-split-addresses */
#include "common.h"
#include "pal/global_002234A4.h"

typedef struct {
    u8 bytes[0xB8];
    s32 fB8;
} PalMenuRecordCopy;

/* Copy the supplied block into the current menu record and clear its flag. */
void func_L00_00773CB8(const PalMenuRecordCopy *source) {
    u8 *record = *(u8 **)((u8 *)D_002234A4 + 0x48);

    *(PalMenuRecordCopy *)(record + 0x28) = *source;
    record[2] = 0;
}
