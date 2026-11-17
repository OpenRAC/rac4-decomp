#include "common.h"

extern void func_004B0158(void);
extern void func_004B01C8(void);
extern void func_004B0710(void);
extern void func_005014B0(void *);
typedef struct State_004B00D0 { u8 pad0[4]; s32 f4; u8 f8; } State_004B00D0;
extern State_004B00D0 D_3095B0;

void func_004B00D0(void *arg0) {
    switch (D_3095B0.f4) {
    case 0:
        break;
    case 1:
        D_3095B0.f4 = 0;
        break;
    case 2:
        func_005014B0(arg0);
        break;
    }
    func_004B0158();
    if (D_3095B0.f8)
        func_004B01C8();
    func_004B0710();
}
