#include "common.h"

typedef void (*Callback)(s32);
typedef struct {
    u8 enabled;
    u8 unknown1[3];
    const char *text;
    Callback callback;
} MenuEntry;

u8 D_0021F700 = 0;
s32 D_0021F704 = 1;
extern MenuEntry D_003D9118[];
extern void func_00466A20(void);
extern s32 func_004E3138(s32, s32, s32);
extern char *func_0045E850(s32);
extern void func_004A0398(s32, f32, f32, f32, f32);
extern void func_004A0F10(s32, s32);
extern void func_004A0D78(s32, s32, MenuEntry *);
extern void func_004A0028(s32, Callback);
extern void *func_004A2AC0(void);
extern void func_00502508(void *);
extern s32 func_00506D28(void *);

void func_004A2BA8(s32 index)
{
    if (D_0021F700) {
        func_00466A20();
        D_0021F700 = 0;
    }
    if (D_0021F704) {
        func_004E3138(5, 0, 0);
        D_0021F704 = 0;
    }
    D_003D9118[0].text = func_0045E850(0x23A2);
    D_003D9118[1].text = func_0045E850(0x23A3);
    D_003D9118[2].text = func_0045E850(0x23A4);
    D_003D9118[3].text = func_0045E850(0x2F25);
    D_003D9118[4].text = func_0045E850(0x14F);
    func_004A0398(index, 0.685f, 0.28f, 0.37109375f, 0.048076923936605453f);
    func_004A0F10(index, 0);
    func_004A0D78(index, 5, D_003D9118);
    func_004A0028(index, NULL);
    func_00502508(func_004A2AC0());
    func_00506D28(func_004A2AC0());
}
