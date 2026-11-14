#include "common.h"

typedef struct {
    u8 pad0[0x20];
    u8 f20;
} Type1;

extern void func_L00_005F3FC8(void *);
extern s32 func_004E2EF0(s32, s32, void *);
extern s32 func_L01_00598028(void *, f32, f32, f32);
extern s32 func_L01_005B2560(void *);

/* Update a non-final object, conditionally start effect 2, and queue it. */
s32 func_L01_004C64A0(Type1 *object) {
    if (object->f20 == 2) {
        return 0;
    }
    if (func_L01_005B2560(object) != 0) {
        func_004E2EF0(2, 0, object);
    }
    func_L01_00598028(object, 32.0f, -1.0f, 0.0f);
    func_L00_005F3FC8(object);
    return 0;
}
