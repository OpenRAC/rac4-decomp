#include "common.h"

extern s32 func_L01_00593D50(void *, f32, f32, f32);

typedef struct {
    u8 pad0[0x20];
    u8 f20;
} Type1;

/* Set the object's flag byte at offset 0x20, then spawn a shadow with fixed coordinates. */
void func_L01_004DE940(Type1 *arg0) {
    if (arg0->f20 == 0) {
        arg0->f20 = 1;
    }
    func_L01_00593D50(arg0, 32.0f, -1.0f, 0.0f);
}
