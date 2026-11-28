#include "pal/object_data.h"

u32 D_L01_00220FA0[2] = { 0x80805040, 0x40007EFF };
u32 D_L01_00220FA8[2] = { 0x40803020, 0x20000080 };
extern void func_L00_00576DE8(void *, void *, void *);

void func_L01_003F9940(PalObject *object) {
    func_L00_00576DE8((u8 *)object->data + 0x170,
                      D_L01_00220FA0, D_L01_00220FA8);
}
