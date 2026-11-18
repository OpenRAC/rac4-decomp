/* Not matching yet: BYTES 16/200 (tools/try_func.py func_L00_00766300 --diff). Not part of the build. */
typedef struct {
    s32 f0;
    s32 f4;
    s32 *f8;
} Slot;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
} Inner;

typedef struct {
    s32 f0;
    s32 f4;
    u8 f8;
    u8 pad9[3];
    s32 fC;
    s32 f10;
    u8 f14;
    u8 pad15[3];
    s32 f18;
    u8 f1C;
    u8 pad1D[3];
    s32 unk20;
    s32 unk24;
    Slot slot[2];
    Inner *f40;
} Outer;

extern u8 D_0021DF99;

void func_L00_00766300(Outer *arg0) {
    s32 i;
    s32 j;
    s32 n;

    arg0->f4 = -1;
    arg0->f8 = 0;
    arg0->fC = -1;
    arg0->f10 = -1;
    arg0->f14 = 0;
    arg0->f1C = 0;
    if (arg0->f40 != 0) {
        if (D_0021DF99 != 0) {
            for (i = 0; i < 2; i++) {
                n = *(s32 *)((u8 *)arg0 + i * 12 + 0x2C);
                for (j = 0; j < n; j++) {
                    s32 w = ((Slot *)((u8 *)arg0 + i * 12 + 0x28))->f8[j];
                    Inner *in = arg0->f40;
                    *(s32 *)(w + in->fC) = in->f1C;
                    in->f1C = w;
                    in->f18 = in->f18 + 1;
                }
            }
        }
        arg0->slot[0].f4 = 0;
        arg0->slot[1].f4 = 0;
    }
}
