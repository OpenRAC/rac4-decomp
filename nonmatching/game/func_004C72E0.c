/* Not matching yet: BYTES 3/196 (tools/try_func.py func_004C72E0 --diff). Not part of the build. */
extern s32 func_0045E038(s32);
extern void func_00497980(s32 arg0);
extern void func_0049B208(s32);
extern void func_0049E790(s32, s32, void (*)(void *), s32, f32, s32, s32, s32);
extern s32 func_00505B20(void);
extern void func_004C73A8(void *);
extern s32 D_0021DE10;
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern s32 D_0021F198;
extern s32 D_241B00[];

// Starts a timed callback when the mode matches, otherwise hands off to func_0049B208.
void func_004C72E0(void) {
    s32 idx;
    s32 mode;

    idx = D_0021F198;
    if (idx == -1) {
        return;
    }
    mode = 1;
    if (D_0021EDD4 == 0) {
        if (D_0021EDD8 == 1) {
            mode = 0x15;
        }
    }
    if (D_0021DE10 == mode && idx < 8) {
        mode = 1;
        if (D_241B00[0] == mode) {
        func_00497980(7);
        func_0049E790(4, func_0045E038(0x362E), func_004C73A8, 3, -1.0f, 0, 0, 0);
            return;
        }
    }
    func_0049B208(func_00505B20());
}
