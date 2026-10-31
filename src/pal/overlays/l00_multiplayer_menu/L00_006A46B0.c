/* cflags: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses -IC:/Users/shaar/Documents/Dev/rac4-decomp/include -IC:/Users/shaar/Documents/Dev/rac4-decomp/tools/ext/rac3-decomp -IC:/Users/shaar/Documents/Dev/rac4-decomp/tools/ext/rac3-decomp/include -IC:/Users/shaar/Documents/Dev/rac4-decomp/tools/ext/rac3-decomp/src/frontbin */
#include "common.h"


extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003F2380();
extern s32 func_003EDF58();
extern void *func_003F1CA8();
extern void *func_003EF110();
extern void *func_003EFF18();
extern s32 func_003EDBD8();
extern void func_003EDC80();
extern void **func_003F2208(void **);
void func_003EFE98(void *, s32);
extern void func_003EFFE8(void *p, f32, f32);
extern void func_003EFFA0(u8 *p, u8, s32);
extern void func_003EE160(void *p, s32, s32);
extern s32 func_003F0BE8(u8 *arg0, s32, s32);
extern s32 func_003EBD20(void *, s32, void *);
extern s32 func_L00_006A46B0(u8 *p, f32 a, f32 b);
extern s32 func_003EAA18(u8 *p, s32 a, s32 b);
extern s32 func_003EAB50(u8 *p, s32 a);
extern s32 func_003EAC70(u8 *p, f32 a, f32 b);
extern s32 func_003EACD8(u8 *p, s32 a);
extern s32 func_003EADF8(u8 *p, s32 a, s32 b);
extern s32 func_003EAF30(u8 *p, s32 a, u8 *out);
extern s32 func_003EB068(u8 *p, s32 a, s32 b);
extern s32 func_003EB0D0(u8 *p, s32 a, s32 b);
extern s32 func_003EB208(u8 *p, f32 a, f32 b);
extern s32 func_003EB270(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003EB418(u8 *p, s32 a);
extern s32 func_003EB540(u8 *p, f32 a, f32 b);
extern s32 func_003EB5B0(u8 *p, s32 a, s32 b);
extern s32 func_003EB618(u8 *p, s32 a);
extern s32 func_003EB670(u8 *p, s32 a, s16 b, s16 c, s32 d);
extern s32 func_003EB7D0(u8 *p, f32 a, f32 b);
extern s32 func_003EB840(u8 *p, s32 a);
extern s32 func_003EB898(u8 *p, s32 a, s32 b);
extern s32 func_003EB900(u8 *p, s32 a, u8 *out);
extern s32 func_003EB968(u8 *p, s32 a, s32 b);
extern s32 func_003EB9D0(u8 *p, s32 a, s32 b);
extern s32 func_003EBA38(u8 *p, f32 a, f32 b);
extern s32 func_003EBAA0(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003EBB78(u8 *p, f32 a, f32 b);
extern s32 func_003EBCC0(u8 *p, f32 a);
extern s32 func_003EBDF8(u8 *p, f32 a);
extern s32 func_003EBE58(u8 *p, f32 a, f32 b);
extern s32 func_003EBEC8(u8 *p, s32 a);
extern s32 func_003EBFF0(u8 *p, s32 a, s32 b);
extern s32 func_003EC058(u8 *p, s32 a);
extern s32 func_003EC0B0(u8 *p, f32 a, f32 b);
extern s32 func_003EC118(u8 *p, s32 a, s32 b);
extern s32 func_003EC180(u8 *p, f32 a, f32 b);
extern s32 func_003EC1E8();
extern s32 func_003EC250();
extern s32 func_003EC2B0(u8 *p, s32 a, s32 b);
extern s32 func_003EC318(u8 *p, s32 a, u8 *out);
extern s32 func_003EC380(u8 *p, s32 a, s32 b);
extern s32 func_003EC3E8(u8 *p, s32 a, s32 b);
extern s32 func_003EC450(u8 *p, f32 a, f32 b);
extern s32 func_003EC4B8(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003EC590(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_003EC6E8(u8 *p, f32 a);
extern s32 func_003EC810(u8 *p, f32 a, f32 b);
extern s32 func_003EC878(u8 *p, s32 a, s32 b);
extern s32 func_003EC8E0(u8 *p, f32 a, f32 b);
extern s32 func_003EC948(u8 *p, s32 a);
extern s32 func_003EC998(u8 *p, s32 a, s32 b);
extern s32 func_003ECA00(u8 *p, s32 a, u8 *out);
extern s32 func_003ECA68(u8 *p, s32 a, s32 b);
extern s32 func_003ECAD0(u8 *p, s32 a, s32 b);
extern s32 func_003ECB38(u8 *p, f32 a, f32 b);
extern s32 func_003ECBA0(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003ECC78(u8 *p, f32 a, f32 b);
extern s32 func_003ECCE0(u8 *p, f32 a, f32 b);
extern s32 func_003ECD48(u8 *p, s32 a, s32 b);
extern s32 func_003ECDB0(u8 *p, f32 a, f32 b);
extern s32 func_003ECE18(u8 *p, s32 a);
extern s32 func_003ECE68();
extern s32 func_003ECF98(u8 *p, s32 a, s32 b);
extern s32 func_003ED000(u8 *p, s32 a, u8 *out);
extern s32 func_003ED068(u8 *p, s32 a, s32 b);
extern s32 func_003ED0D0(u8 *p, s32 a, s32 b);
extern s32 func_003ED138(u8 *p, f32 a, f32 b);
extern s32 func_003ED1A0(u8 *p, f32 a);
extern s32 func_003ED1F8(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003ED2D0(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern s32 func_003ED430();
extern s32 func_003ED488();
extern s32 func_003ED5A8(u8 *p, s32 a, s32 b);
extern s32 func_003ED610(u8 *p, s32 a, u8 *out);
extern s32 func_003ED678(u8 *p, s32 a, s32 b);
extern s32 func_003ED6E0(u8 *p, s32 a, s32 b);
extern s32 func_003ED748(u8 *p, f32 a, f32 b);
extern s32 func_003ED7B0(u8 *p, f32 a, f32 b);
extern s32 func_003ED820(u8 *p, s32 a, s32 b);
extern s32 func_003ED888(u8 *p, f32 a, f32 b);
typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
extern void *func_003EE760();
extern void *func_003F0708();




/* localdecomp:start func_L00_006A46B0 */
typedef struct { u8 pad[20]; s32 (*isA)(void *, s32); } VT_E;
extern s32 D_00220530[];
s32 func_L00_006A46B0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_00220530[0])) {
        *(f32 *)(p + 20) = a;
        *(f32 *)(p + 24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L00_006A46B0 */
