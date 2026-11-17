#include "common.h"

extern s32 func_0011D5D8(const char *fmt,...);
extern void func_00126E20(s32);
extern void func_00127438(void *, void *);
extern s32 func_0012A718();
extern s32 func_0012A918(void *p);
extern s32 func_00157F98(void);
extern char D_001A47F0[];
extern char D_001A4900[];
extern char D_001A4930[];
extern char D_1C1FC0[];
extern s32 D_1C2000[];
extern u32 D_21D9C0;
extern s32 D_0021DCB0;
s32 D_0021DCF0 = 0;
s32 D_0021DD20 = 0;

// Waits for the slot at D_1C1FC0 to open, stores arg0 and returns the reply value or 0 on failure.
s32 func_00158400(s32 arg0) {
    D_0021DCB0 = 0;
    if (D_0021DCF0 != 0) {
        if (D_0021DD20 == 0) {
            func_0011D5D8(D_001A4900);
        }
        return 0;
    }
    D_21D9C0 = 0xFFFFFFFF;
    func_00127438(&D_21D9C0, &D_21D9C0 + 1);
    D_1C2000[0] = arg0;
    while (func_0012A918(D_1C1FC0) != 0) {
        if (D_0021DD20 == 0) {
            func_0011D5D8(D_001A47F0);
        }
        func_00157F98();
        func_00126E20(0);
    }
    if (func_0012A718(D_1C1FC0, 0x57, 1, D_1C2000, 4, &D_21D9C0, 4, 0, 0) < 0) {
        if (D_0021DD20 == 0) {
            func_0011D5D8(D_001A4930);
        }
        D_0021DCB0 = 0x106;
        return 0;
    }
    if (D_21D9C0 == 0xFFFFFFFF) {
        do {
            func_00126E20(0);
        } while (D_21D9C0 == 0xFFFFFFFF);
    }
    return D_21D9C0;
}
