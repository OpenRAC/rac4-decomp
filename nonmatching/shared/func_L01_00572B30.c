/* Not matching yet: BYTES 83/180 (tools/try_func.py func_L01_00572B30 --diff) (tools/try_func.py func_L01_00572B30 --diff). Not part of the build. */
typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    u8 pad14[8];
    u8 unk1C;
} S0;

typedef struct {
    u8 pad0[0x11];
    u8 unk11;
} S1;

extern s32 func_L01_00572BE8(void *a0, s32 a1, f32 a, f32 b, f32 c, f32 d);
extern s32 func_L01_00572EC8(void *a0, s32 a1, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f);

s32 func_L01_00572B30(S0 *arg0, S1 *arg1, s32 arg2, f32 fparg0) {
    if (arg0 != 0) {
        if ((u32)(arg0->unk1C - 1) < 3U) {
            if (arg1 != 0) {
                if (arg1->unk11 < 7U) {
                    switch (arg0->unk1C) {
                    case 1:
                        return func_L01_00572BE8(arg1, arg2, arg0->unk0, arg0->unk4, arg0->unk8, fparg0);
                    case 3:
                        return func_L01_00572EC8(arg1, arg2, arg0->unk0, arg0->unk4, arg0->unk8, arg0->unkC, arg0->unk10, fparg0);
                    default:
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}
