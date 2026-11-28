#include "pal/moby_class.h"

extern u8 *D_L05_00222C14;
extern u8 *D_L05_00222C30;
extern void *func_0047C510(void *);

/* Set the caller flag, then update configs for mobys outside class 0x268B. */
void func_L05_004AD890(u8 *arg0) {
    u8 *cur;
    void *cfg;

    arg0[0x30] = 0xFF;
    cur = D_L05_00222C14;
    while (cur < D_L05_00222C30) {
        if (((PalMobyClassView *)cur)->classId != 0x268B) {
            cfg = func_0047C510(cur);
            if (cfg != NULL) {
                *(f32 *)((u8 *)cfg + 0x38) = 48.0f;
                *(f32 *)((u8 *)cfg + 0x34) = 48.0f;
                *(s16 *)(cur + 0x32) = 0x80;
            }
        }
        cur += sizeof(PalMobyClassView);
    }
}
