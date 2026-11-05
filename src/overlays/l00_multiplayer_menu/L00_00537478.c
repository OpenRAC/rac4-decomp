/* cflags: @ee29 -O2 -G0 */
#include "common.h"
typedef struct { s32 type; s32 value; } Type1;
void func_005362F8(s32);
void func_L00_00535898(s32);
void func_L00_00537478(Type1 *p) {
    if (p != NULL && p->value != 0) {
        switch (p->type) {
        case 6:
            func_L00_00535898(p->value);
            break;
        case 2: case 3: case 4:
        case 0x10: case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16:
        case 0x17: case 0x18: case 0x19: case 0x1A: case 0x1B: case 0x1C:
        case 0x1E: case 0x102:
            func_005362F8(p->value);
            break;
        }
        p->type = 0;
        p->value = 0;
    }
}
