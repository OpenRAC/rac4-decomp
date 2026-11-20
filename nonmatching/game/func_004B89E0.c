/* Not matching yet: SIZE ours 204 / retail 200 (tools/try_func.py func_004B89E0 --diff). Not part of the build. */
extern u8 D_003D9370[];
extern u8 D_221790[];
extern u8 D_30A160[];
extern void func_0049C158(s32, s32, s32, s32);
extern s32 func_004A1A60(s32 *, s32);
extern s32 func_00505328(s32, u32);
extern s32 func_00505B20(void);

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Blk;

void func_004B89E0(void) {
    s32 slot;
    s32 i;

    slot = func_00505B20();
    i = ((Blk *)(D_30A160 + slot * 0x10))->unk4;
    func_0049C158(slot, 0, func_004A1A60((s32 *)D_221790, *(s32 *)(D_003D9370 + i * 0x14 + 4)), 0);
    func_00505328(func_004A1A60((s32 *)D_221790, *(s32 *)(D_003D9370 + i * 0x14 + 8)), 0x80D0D0D0);
    func_00505328(func_004A1A60((s32 *)D_221790, *(s32 *)(D_003D9370 + i * 0x14 + 0xC)), 0x80D0D0D0);
}
