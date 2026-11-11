/* Not matching yet: BYTES 10/128 (tools/try_func.py func_L00_005C5428 --diff). Not part of the build. */
extern void func_00126E20(s32);
extern void func_138FF0(void *, s32, s32, s32, s16, s16, s16, s16);
extern void func_1392B0(void *, s32);
extern s32 D_001DFCF8_[];
#define D_001DFCF8 (D_001DFCF8_[0])
extern s32 D_001D3F40_[];
#define D_001D3F40 (D_001D3F40_[0])

/* Fills a local 0x70-byte block from two globals and the four coordinates, then submits it with arg4. */
void func_L00_005C5428(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    s32 buf[28];

    func_138FF0(buf, (D_001DFCF8 << 8) >> 16, (D_001D3F40 << 10) >> 16, 0x30, arg0, arg1, arg2, arg3);
    func_00126E20(0);
    func_1392B0(buf, arg4);
}
