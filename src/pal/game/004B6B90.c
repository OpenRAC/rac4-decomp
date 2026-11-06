#include "common.h"

extern s32 D_003099F0[];
extern u8 D_0021EE98;
extern s32 D_0021DE54;
extern char D_0021F8C0[];
extern u8 D_00171DB8[];
extern void *func_00511CC0(s32);
extern const char *func_0045E850(s32);
extern s32 func_0011D920(char *, const char *, ...);

void func_004B6B90(s32 arg0) {
    s32 object;
    const char *format;
    s32 index;
    const char *first;
    const char *second;
    s32 item;
    s32 table;

    item = arg0 * 0x1F8 + (s32)D_003099F0;
    if (D_0021EE98 != 0) {
        object = D_0021DE54;
    } else {
        object = *(s32 *)((u8 *)func_00511CC0(arg0) + 0x2F00);
    }
    index = *(u8 *)(object + 0x54C) * 4 + *(u8 *)(object + 0x558);
    item += 0x114;
    format = D_0021F8C0;
    first = func_0045E850(0x3209);
    table = (s32)D_00171DB8 - (0 - index);
    second = func_0045E850(*(u8 *)(table + 0xB4) != 0 ? 0x175 : 0x176);
    func_0011D920((char *)item, format, first, second);
}
