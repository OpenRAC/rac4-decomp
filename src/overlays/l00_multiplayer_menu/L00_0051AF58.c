/* cflags: @ee29 */
#include "common.h"

typedef struct { u8 b[64]; } Blob64;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    Blob64 f18;
} Rec;

s32 func_L00_00540F30(s32, s32);

s32 func_L00_0051AF58(Rec *arg0, Rec *arg1) {
    arg0->f0 = arg1->f0;
    if (func_L00_00540F30(arg0->f4, arg1->f4) == 0) {
        return 0;
    }
    if (func_L00_00540F30(arg0->f8, arg1->f8) == 0) {
        return 0;
    }
    if (func_L00_00540F30(arg0->fC, arg1->fC) == 0) {
        return 0;
    }
    arg0->f10 = arg1->f10;
    arg0->f14 = arg1->f14;
    arg0->f18 = arg1->f18;
    return 1;
}
