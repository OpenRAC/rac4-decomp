/* Not matching yet: BYTES 47/112 (tools/try_func.py func_L00_007321E0 --diff) (tools/try_func.py func_L00_007321E0 --diff). Not part of the build. */
extern void func_0011A370(u8 *, u8 *, s32);

extern s32 D_0021DE10;
extern u8 *D_0021DB84;
extern u8 *D_0021DB88;

void func_L00_007321E0(u8 *arg0) {
    *(s32 *)(arg0 + 0x28) = 0;
    if (D_0021DE10 == 0) {
        if (D_0021DB84 != 0) {
            arg0[0x2C] = *D_0021DB88;
            func_0011A370(arg0 + 0x2D, D_0021DB84, *D_0021DB88);
            return;
        }
    }
    arg0[0x2C] = 8;
}
