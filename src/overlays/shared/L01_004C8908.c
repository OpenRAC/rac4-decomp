#include "common.h"

extern void func_004C8878(void *, void *, void *);

s64 D_00221FB8 = 0;
s64 D_00221FC0 = 0;

/* runs func_004C8878 on the six sub-records of the linked object */
void func_L01_004C8908(u8 *object)
{
    u8 *p = *(u8 **)(object + 0xAC);

    func_004C8878(p + 0x5A0, &D_00221FB8, &D_00221FC0);
    func_004C8878(p + 0x620, &D_00221FB8, &D_00221FC0);
    func_004C8878(p + 0x6A0, &D_00221FB8, &D_00221FC0);
    func_004C8878(p + 0x720, &D_00221FB8, &D_00221FC0);
    func_004C8878(p + 0x7A0, &D_00221FB8, &D_00221FC0);
    func_004C8878(p + 0x820, &D_00221FB8, &D_00221FC0);
}
