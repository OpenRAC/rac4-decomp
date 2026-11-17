/* Not matching yet: BYTES 2/184 (tools/try_func.py func_004BA620 --diff). Not part of the build. */
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00505328(s32 handle, u32 value);
extern s32 func_00505B20(void);

extern u8 D_003D9528[];
extern s32 D_2217E0;
extern u8 D_30A490[];

void func_004BA620(void)
{
    u8 *base;
    s32 s1;
    u8 a2;
    u32 s3;

    base = D_30A490;
    base = base + func_00505B20() * 0x14;
    s1 = *(s32 *)(base + 4) * 0x14;
    a2 = D_003D9528[s1];
    s3 = (a2 != 0) ? 0x80808080 : 0x80404040;
    func_00505328(func_004A1A60(&D_2217E0, *(s32 *)(D_003D9528 + s1 + 8)), s3);
    func_00505328(func_004A1A60(&D_2217E0, *(s32 *)(D_003D9528 + s1 + 0xC)), s3);
}
