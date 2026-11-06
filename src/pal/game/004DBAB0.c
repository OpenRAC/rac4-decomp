#include "common.h"

typedef struct {
    s32 kind;
    s32 item;
    s32 cost;
    s32 fC;
    s32 f10;
    s32 label;
} Item;
extern u8 D_00322EA4[];
extern s32 D_0021EE54;
extern s32 D_0021EE58;
extern s32 D_00322F38[];
extern s32 func_004E7EC8(const Item *item);
extern void func_004DB998(s32 choice);
extern const char *func_0045E850(s32 id);
extern void func_0049F4C8(s32 mode, const char *label,
                          void (*action)(s32), s32 buttons,
                          s32 f4, s32 f5, s32 f6, f32 timeout);
extern void func_004985F0(s32 sound);

void func_004DBAB0(void)
{
    u8 *list = D_00322EA4;
    u32 row;
    s32 selected;
    Item *item;
    s32 allowed;

    if (*(s32 *)(list + 0x50) != 0) {
        selected = *(s32 *)(list + 0x54);
        if (selected < 0) {
            row = 0;
        } else {
            row = *(u32 *)(list + 0x34) + (u32)selected * 24;
        }
        allowed = 1;
        item = *(Item **)(row + 8);
        if (D_0021EE54 == 0 && D_0021EE58 == 1 && item->label == 0x30EB) {
            if (D_00322F38[0] == 0) {
                allowed = 0;
            }
        }
        if (allowed != 0) {
            if (func_004E7EC8(item) != 0) {
                if (item->cost <= 0) {
                    func_004DB998(1);
                } else {
                    func_0049F4C8(4, func_0045E850(0x8D0), func_004DB998,
                                  3, 0, 0, 0, -1.0f);
                }
            } else {
                func_004985F0(4);
            }
        } else {
            func_004985F0(4);
        }
    }
}
