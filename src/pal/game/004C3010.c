/* cflags: -O2 -G8 -Wa,-G0 -Wuninitialized */
#include "common.h"
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))

s32 func_0011D920(void *, const char *, ...); /* extern */
s32 func_0045E850(s32);                       /* extern */
s32 func_00498518(s32);                       /* extern */
void func_00498818(s32, s32, s32, f32, f32);  /* extern */
s32 func_00498FA8(s32, s32, s32, s32, s32);   /* extern */
s32 func_00499650(s32, s32);                  /* extern */
s32 func_004A2798(void *, s32);               /* extern */
s32 func_005062D0(s32, s32);                  /* extern */
s32 func_00506760(s32, s32, s32, s32, s32);   /* extern */
s32 func_00506BB8(void *);                    /* extern */
void *func_00511CC0(s32);                     /* extern */
s16 func_005492C0(s32, s32);                  /* extern */
s32 func_00549368(s32, s32);                  /* extern */
s16 func_00549398(s32, s32);                  /* extern */
f32 func_005497E8(s32, s32);                  /* extern */
s32 func_00549A80(void *, s32);               /* extern */
void *func_0054A290(s32, s32);                /* extern */
extern char D_0021FA48[];
extern char D_0021FA50[];
extern s32 D_00221980;
extern s32 D_00221988;
extern u8 D_0030B7F8[];

/* Updates the selected record text and its associated interface controls. */
void func_004C3010(void *arg0) {
    const char *format;
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_16_3;
    s32 temp_16_4;
    s32 temp_16_5;
    s32 temp_16_6;
    s32 temp_17;
    s32 temp_17_2;
    s32 temp_17_3;
    s32 temp_20;
    s32 temp_2;
    u8 *temp_21;
    void *temp_2_2;

    temp_2 = func_00506BB8(arg0);
    temp_21 = (temp_2 * 0x74) + D_0030B7F8;
    temp_20 = func_00498518(M2C_FIELD(temp_21, s32 *, 0xC));
    temp_2_2 = func_00511CC0(temp_2);
    format = D_0021FA48;
    temp_17 = func_00549368(M2C_FIELD(temp_2_2, s32 *, 0x26E4), temp_20);
    func_0011D920((void *)((unsigned char *)(temp_21) + (28)), format, temp_17,
                  func_00549398(M2C_FIELD(temp_2_2, s32 *, 0x26E4), temp_20));
    func_0011D920((void *)((unsigned char *)(temp_21) + (52)), D_0021FA50,
                  func_005492C0(M2C_FIELD(temp_2_2, s32 *, 0x26E4), temp_20) + 1);
    if (temp_20 == 8) {
        temp_16 = func_004A2798(&D_00221980, 72);
        func_005062D0(temp_16, func_0045E850(13490));
        func_0011D920((void *)((unsigned char *)(temp_21) + (44)), D_0021FA50,
                      func_00549A80((void *)M2C_FIELD(temp_2_2, s32 *, 0x26E4), 8));
    } else {
        temp_16_2 = func_004A2798(&D_00221980, 72);
        func_005062D0(temp_16_2, func_0045E850(9119));
        func_0011D920((void *)((unsigned char *)(temp_21) + (44)), D_0021FA50,
                      func_00549A80((void *)M2C_FIELD(temp_2_2, s32 *, 0x26E4), temp_20));
    }
    temp_16_3 = func_004A2798(&D_00221980, 63);
    func_005062D0(temp_16_3, func_00498FA8(temp_2, temp_20, 1, 1, 1));
    temp_16_4 = func_004A2798(&D_00221988, 83);
    func_005062D0(temp_16_4, func_0045E850(M2C_FIELD(func_0054A290(temp_20, 0), s16 *, 0xA)));
    temp_17_2 = func_00499650(1, 2);
    temp_16_5 = func_00499650(1, 0);
    func_00506760(func_004A2798(&D_00221980, 69), temp_17_2, temp_16_5, temp_17_2, temp_16_5);
    temp_17_3 = func_004A2798(&D_00221980, 67);
    temp_16_6 = func_004A2798(&D_00221980, 69);
    func_00498818(temp_17_3, temp_16_6, 0,
                  func_005497E8(M2C_FIELD(temp_2_2, s32 *, 0x26E4), temp_20), 0.00400000019f);
    M2C_FIELD(temp_21, s32 *, 8) = (s32)(M2C_FIELD(temp_21, s32 *, 8) & ~2);
}
