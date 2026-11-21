/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 pad0[0x38];
    s32 unk38;
} Type1;
typedef struct {
    Type1 *unk0;
    s32 pad4;
    s32 unk8;
    void *unkC;
} Type0;
extern void func_0011A518(void *, s32, s32);
extern void func_004FAD28(void *);
extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
extern void *func_L00_004FACD8(s32);
// Points the slot at arg1 (allocating its buffer when needed) and resizes the buffer to its size; 0 on allocation failure.
s32 func_L00_00548070(Type0 *arg0, Type1 *arg1) {
    s32 temp_a2;
    void *temp_v0;

    if (arg0->unk0 != NULL) {
        func_0011A518(arg0->unkC, 0, arg0->unk8);
        if (arg0->unk8 != arg1->unk38) {
            func_004FAD28(arg0->unkC);
            arg0->unkC = NULL;
            arg0->unk8 = 0;
        }
    }
    if (arg1 != NULL) {
        if (arg0->unkC == NULL) {
            temp_v0 = func_L00_004FACD8(arg1->unk38);
            arg0->unkC = temp_v0;
            if (temp_v0 == NULL) {
                func_L00_004F84C8(6, 0x76, 0x21, 0, 0);
                return 0;
            }
        }
    }
    arg0->unk0 = arg1;
    if (arg1 != NULL) {
        arg0->unk8 = arg1->unk38;
    }
    temp_a2 = arg0->unk8;
    if (temp_a2 > 0) {
        func_0011A518(arg0->unkC, 0, temp_a2);
    }
    return 1;
}
