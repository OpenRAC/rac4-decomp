#include "common.h"

/* Stores func_004A0208's result at offset 8 of the 0x1F8-byte slot of D_3098F0 for the current owner, clears D_0021F7E8 and registers the owner with count 0x16. */
extern void func_00497980(s32 arg0);
extern void func_0049B1A0(s32 param, s32 count);
extern s32 func_004A0208(s32 arg0);
extern s32 func_00505B20(void);
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s8 pad[0x1F8 - 12];
} Slot;
extern Slot D_3098F0[];
s8 D_0021F7E8 = 0;

void func_004B74F8(void) {
    s32 idx = func_00505B20();
    s32 val = func_004A0208(idx);
    D_0021F7E8 = 0;
    D_3098F0[idx].f8 = val;
    func_0049B1A0(idx, 0x16);
    func_00497980(6);
}
