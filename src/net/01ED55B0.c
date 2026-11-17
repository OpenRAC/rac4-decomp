/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 w[12]; } Info;
extern u8 D_001B7690[];
extern void *func_0011A370(void *, const void *, u32);
void func_01ED55B0(Info *p) {
    Info t = *p;
    func_0011A370(D_001B7690, &t, sizeof(t));
}
