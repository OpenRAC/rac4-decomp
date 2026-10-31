/* Not matching yet: BYTES 2/124 (tools/try_func.py func_004D73C8 --diff). Not part of the build. */
extern void func_00497980(s32 arg0);
extern s32 func_004D7250(s32 index);
extern void func_00501498(s32 *arg0);
extern void func_00505AD8(s32 a);
extern s32 func_00505B20(void);
extern void func_00505C90(s32);

u8 D_0021FC11 = 0;

/* Clears the flag at D_0021FC11 if it is set, otherwise reports 0xB through func_00497980. */
void func_004D73C8(s32 arg0) {
    s32 temp_s1;

    temp_s1 = func_00505B20();
    func_00505AD8(arg0);
    func_00501498(func_004D7250(arg0));
    func_00505C90(func_004D7250(arg0));
    func_00505AD8(temp_s1);
    if (D_0021FC11 == 0) {
        func_00497980(0xB);
    } else {
        D_0021FC11 = 0;
    }
}
