#include "common.h"

/* Calls the optional hook D_21DBEC, then clears the record at arg0 when its id does not match the current table entry. */
extern void (*D_21DBEC)();
extern u8 D_00172160[];
extern s32 func_0015C748(void);
extern u8 func_0015C770(void);

void func_0015EF88(void *arg0) {
    s32 temp_a0;
    u8 *tbl;

    if (D_21DBEC != NULL) {
        D_21DBEC();
    }
    temp_a0 = *(s32 *)arg0;
    tbl = D_00172160;
    if ((*(s32 *)(tbl + 0x10) != temp_a0 || *(s32 *)(tbl + 0x258) == 0) && (func_0015C770() == 0 || func_0015C748() != *(s32 *)arg0)) {
        *(s16 *)((u8 *)arg0 + 0x8) = 0;
        *(s16 *)((u8 *)arg0 + 0xA) = 0;
        *(s32 *)arg0 = -1;
        *(s16 *)((u8 *)arg0 + 0xE) = 0;
    }
}
