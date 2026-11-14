/* Not matching yet: BYTES 21/176 (tools/try_func.py func_00499320 --diff). Not part of the build. */
/* cflags: -fno-gcse */
typedef struct {
    u8 unk0;
    u8 pad[7];
    s32 unk8;
    u8 unkC;
    u8 pad2[3];
} Spot;

extern Spot D_2F3750[];
extern s32 D_0021DDB4;

Spot *func_00499320(s32 arg0, s32 arg1)
{
    Spot *spot = D_2F3750;
    Spot *best = 0;
    s32 threshold = (arg0 - 1) / 0x4C00 + 1;
    Spot *end = D_2F3750 + 32;

    do {
        if (spot->unk0 == 0
            && spot->unk8 >= threshold
            && ((D_0021DDB4 == 3 && arg1 != 0) || spot->unkC == 0)
            && (best == 0 || spot->unk8 < best->unk8)) {
            best = spot;
        }
        spot++;
    } while ((s32)spot < (s32)end);

    if (best != 0) {
        best->unk0 = 1;
    }
    return best;
}
