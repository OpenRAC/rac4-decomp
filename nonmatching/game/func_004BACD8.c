/* Not matching yet: BYTES 4/120 (tools/try_func.py func_004BACD8 --diff). Not part of the build. */
extern void func_00497980(s32 arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_004BAD50(s32 a0);
extern void func_00505238(s32, void *, s32);
extern s32 D_0021DE6C;
extern s32 D_003D95AC_[];
#define D_003D95AC (D_003D95AC_[0])
extern s8 D_0021F8D8;
s8 D_0021F8DA = 0;
extern s32 D_2217E0[];
extern s32 D_30A4E0[];

/* Calls func_00497980 with 4 or 0xB, clears two flags, then copies 0x30 bytes from table entry D_0021DE6C. */
void func_004BACD8(s32 arg0) {
    s32 *a;
    s32 b;
    s32 r;

    if (arg0 == 0) {
        func_00497980(4);
        func_004BAD50(0);
    } else {
        func_00497980(0xB);
    }
    a = D_2217E0;
    b = D_003D95AC;
    D_0021F8DA = 0;
    D_0021F8D8 = 0;
    r = func_004A1A60(a, b);
    func_00505238(r, D_0021DE6C * 0x30 + (u8 *)D_30A4E0, 0x30);
}
