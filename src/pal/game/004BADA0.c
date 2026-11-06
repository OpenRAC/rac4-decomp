#include "common.h"

typedef struct Entry {
    s32 status;
    u8 unknown4[0x10];
} Entry;

extern Entry D_0030A490[];
extern char D_0030A360[];
u32 D_0021F970 = 0;
u32 D_0021F974 = 0;
u8 D_0021F978 = 0;
u8 D_0021F979 = 0;
extern u8 D_0021F97A;

extern s32 func_00506BB8(void);
extern void func_00502520(s32 *group);
extern void func_004BB6A0(void);
extern void func_004BBB50(s32 mode);
extern char *func_0045E850(s32 id);
extern s32 func_0011D920(char *dest, const char *format, ...);
extern void func_004BBAD8(s32 result);
extern void func_0049F4C8(s32 context, const char *text, void (*callback)(s32),
                          s32 mode, s32 arg4, s32 arg5, s32 arg6, f32 duration);
extern void func_004985F0(s32 mode);
extern void func_0049FC68(s32 context);

void func_004BADA0(s32 *group)
{
    s32 context = func_00506BB8();
    Entry *entry = (Entry *)((u32)D_0030A490 + (u32)context * sizeof(Entry));
    switch (entry->status) {
    case 1:
        entry->status = 0;
        break;
    case 2:
        func_00502520(group);
        break;
    case 0:
        func_004BB6A0();
        break;
    }
    if (D_0021F979) {
        D_0021F970++;
        if ((s32)D_0021F970 >= 15) {
            func_004BBB50(1);
            D_0021F978 = 1;
            D_0021F970 = 0;
            D_0021F974 = 0;
            func_0011D920(D_0030A360, func_0045E850(0x3263), 15);
            func_0049F4C8(func_00506BB8(), D_0030A360, func_004BBAD8, 3, 0, 1, 0, -1.0f);
            D_0021F979 = 0;
        }
    }
    if (D_0021F978) {
        D_0021F974++;
        if ((s32)D_0021F974 >= 900) {
            func_004985F0(4);
            func_0049FC68(context);
            D_0021F978 = 0;
            func_004BBB50(0);
            D_0021F97A = 0;
        } else {
            s32 remaining = (s32)(900U - D_0021F974) / 60 + 1;
            func_0011D920(D_0030A360, func_0045E850(0x3263), remaining);
        }
    }
}
