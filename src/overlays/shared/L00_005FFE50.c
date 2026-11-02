#include "common.h"

extern s32 func_00157F98(void);
extern void func_00600288(void *, f32);
extern u8 D_003E4E10[];
extern f32 D_0021DE04;

// Set bit 1 of byte 7 in each 0x50-byte record of D_003E4E10 (three records) whose byte 8 is nonzero; when arg1 is set, call func_00600288 with arg0 and func_00157F98.
void func_L00_005FFE50(s32 arg0, s32 arg1) {
    u8 *v1 = D_003E4E10;
    u8 *a2 = D_003E4E10 + 0xF0;
    do {
        if (v1[8] != 0) {
            v1[7] |= 2;
        }
        v1 += 0x50;
    } while ((s32) v1 < (s32) a2);
    if (arg1 != 0) {
        func_00600288((void *) arg0, D_0021DE04);
        func_00157F98();
    }
}
