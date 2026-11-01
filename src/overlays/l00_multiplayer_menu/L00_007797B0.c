#include "common.h"
typedef struct { u32 words[7]; } Copy;
typedef struct { char pad[0x154]; u8 flag; char pad2[3]; Copy data; } Target;
typedef struct { char pad[0x1d]; u8 flag; char pad2[0x46]; Target *target; } Owner;
extern Owner *D_002233A4;
// Clear the flag and copy the record when the owner permits it.
void func_L00_007797B0(Copy *arg0) {
    Owner *owner = D_002233A4;
    Target *target = owner->target;
    if (!owner->flag) {
        target->flag = 0;
        target->data = *arg0;
    }
}
