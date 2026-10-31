#include "common.h"

/* Stores func_004A0208's result at offset 0xC of the 0x1F8-byte slot of D_3098F0 for the current owner and calls func_0047F568 with category 9. */
extern void func_0047F568(s32, s32, s32, s32, s32);
extern s32 func_004A0208(s32 arg0);
extern s32 func_00505B20(void);
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s8 pad[0x1F8 - 16];
} Slot;
extern Slot D_3098F0[];

void func_004B7558(void) {
    s32 idx = func_00505B20();
    s32 val = func_004A0208(idx);
    D_3098F0[idx].fC = val;
    func_0047F568(9, 1, 0, 0, 0);
}
