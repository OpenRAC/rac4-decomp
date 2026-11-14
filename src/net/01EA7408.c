/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 (*f0)(void); void (*f4)(void); } Drv;
extern Drv *D_00167F34;
extern s32 D_00167F8C;
extern char D_001B2188[0x224];
extern char D_001B23B0[0xC];
extern void func_01EA8968(void);
extern void *func_0011A518(void *, s32, s32);
s32 func_01EA7408(void) {
    s32 r;
    if (D_00167F34 == 0) {
        return 5;
    }
    if (D_00167F8C == 0) {
        r = D_00167F34->f0();
        if (r != 0) {
            return r;
        }
        func_01EA8968();
        func_0011A518(D_001B2188, 0, sizeof(D_001B2188));
        func_0011A518(D_001B23B0, 0, sizeof(D_001B23B0));
    }
    D_00167F8C++;
    return 0;
}
