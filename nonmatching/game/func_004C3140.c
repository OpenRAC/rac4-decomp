/* Not matching yet: BYTES 7/104 (tools/try_func.py func_004C3140 --diff). Not part of the build. */
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00505328(s32, s32);
extern s32 func_00505B20(void);
extern u8 D_003D2340[];
extern u8 D_221880[];
extern u8 D_30B7F8[];

// Take the owner's entry (0x74 bytes each in D_30B7F8), index D_003D2340 by its word at 0x10 (8-byte items), and pass the item to func_004A1A60 and then func_00505328 with 0x80808080.
void func_004C3140(void) {
    u8 *base;
    s32 idx;
    s32 r;

    base = D_30B7F8;
    idx = func_00505B20();
    base = base + idx * 0x74;
    r = func_004A1A60((s32 *)D_221880, *(s32 *)(D_003D2340 + *(s32 *)(base + 0x10) * 8));
    func_00505328(r, 0x80808080);
}
