#include "common.h"

extern u8 D_001723B0[];
typedef struct {
    u8 pad0[0x104];
    u8 ids[10];
    u8 pad10E[0x124 - 0x10E];
    f32 vals[10];
} Board;
extern Board *D_0021DFE8;
extern u8 D_001725F0[];
extern s32 func_0070C410(s32);
extern void func_0070CB48(void *, s32, void *);
extern s32 func_L00_0070C368(void *);
extern void func_L00_0070C3E0(void *, s32);
extern void func_L00_0070C528(void *, s32, s32);
extern s32 func_L00_0077B8A0(f32);

void func_L00_0075B8F8(void) {
    u8 buf[0x470];
    s32 sum;
    s32 count;
    s32 i;
    s32 avg;

    if (D_001723B0[0] != 0 && D_0021DFE8 != NULL) {
        sum = 0;
        count = 0;
        for (i = 0; i < 10; i++) {
            if (D_0021DFE8->ids[i] != 0xFF) {
                count++;
                sum += func_L00_0077B8A0(D_0021DFE8->vals[i]);
            }
        }
        if (count > 0) {
            avg = (f32)sum / (f32)count;
            func_L00_0070C368(buf);
            func_L00_0070C528(buf, func_0070C410(4), avg);
            func_0070CB48(buf, 4, D_001725F0);
            func_L00_0070C3E0(buf, 2);
        }
    }
}
