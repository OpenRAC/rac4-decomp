#include "common.h"
typedef struct Item {
    u8 disabled;
    u8 pad[3];
    const char *text;
    s32 value;
} Item;
extern Item D_003D9170[];
extern u8 D_00171E75[];
extern const char *func_0045E850(s32);
extern void func_004A0F28(s32, s32);
extern void func_004A0398(s32, f32, f32, f32, f32);
extern void func_004A0F10(s32, s32);
extern void func_004A0D78(s32, s32, const Item *);
extern void func_004A3630(void);
extern void func_004A0028(s32, void (*)(void));
extern void func_004985F0(s32);
void func_004A3408(s32 a0)
{
    D_003D9170[0].text = func_0045E850(0x150);
    D_003D9170[1].text = func_0045E850(0x151);
    D_003D9170[2].text = func_0045E850(0x153);
    D_003D9170[3].text = func_0045E850(0x154);
    D_003D9170[4].text = func_0045E850(0x152);
    if (D_00171E75[0] == 2) {
        goto case_two;
    }
    if (D_00171E75[0] != 4) {
        goto fallback;
    }
    func_004A0F28(a0, 2);
    goto done;
case_two:
    func_004A0F28(a0, 1);
    goto done;
fallback:
    func_004A0F28(a0, 0);
done:
    func_004A0398(a0, 0x1.5eb852p-1f, 0x1.1eb852p-2f, 0.37109375f, 0x1.89d89ep-5f);
    func_004A0F10(a0, 0);
    func_004A0D78(a0, 5, D_003D9170);
    func_004A0028(a0, func_004A3630);
    func_004985F0(0xB);
}
