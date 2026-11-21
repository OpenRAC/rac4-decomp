#include "common.h"

typedef struct { u8 b[0x190]; } Type1;
extern void func_0015BA20(s32 arg0, Type1 *arg1);
extern Type1 D_003DD338[];
extern Type1 D_003DD4C8[];

/* Copies the 0x190-byte record into one of two slots, then hands it to func_0015BA20. */
void func_L00_00772480(s32 arg0, s32 arg1, Type1 *arg2) {
    if (arg1 == 0) {
        D_003DD338[0] = *arg2;
    } else {
        D_003DD4C8[0] = *arg2;
    }
    func_0015BA20(arg1, arg2);
}
