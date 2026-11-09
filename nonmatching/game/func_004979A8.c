/* Not matching yet: BYTES 3/308 (tools/try_func.py func_004979A8 --diff). Not part of the build. */
extern void func_0011D920(void *, void *, ...);
extern u8 D_0021F568[];
extern u8 D_0021F570[];
extern u8 D_0021F580[];
extern u8 D_003D1240[];
void func_004979A8(void *output, s32 value, s32 showPlus) {
    s32 sign = value >= 0 ? (showPlus ? 0x2B : 0x20) : 0x2D;
    value = value <= 0 ? -value : value;
    if (value < 1000) {
        func_0011D920(output, D_0021F568, sign, value);
    } else if (value <= 0xF423F) {
        func_0011D920(output, D_0021F570, sign, value / 1000, value % 1000);
    } else if (value <= 0x3B9AC9FF) {
        func_0011D920(output, D_0021F580, sign, value / 1000000, (value % 1000000) / 1000, value % 1000);
    } else {
        func_0011D920(output, D_003D1240, sign, value / 1000000000, (value % 1000000000) / 1000000, (value % 1000000) / 1000, value % 1000);
    }
}
