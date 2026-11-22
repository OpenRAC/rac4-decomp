/* cflags: -mno-split-addresses */
#include "common.h"
s32 D_00221B60 = 0;
extern s32 D_00223C90[];
void *func_L01_00489400(s32 arg0, s32 arg1, s32 *arg2) {
    switch (arg1) { case 3: *arg2 = 8; return &D_00221B60; case 15: *arg2 = 0x10; return D_00223C90; default: return 0; }
}
