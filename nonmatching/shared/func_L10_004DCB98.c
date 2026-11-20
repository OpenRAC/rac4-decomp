/* Not matching yet: BYTES 16/192 (tools/try_func.py func_L10_004DCB98 --diff). Not part of the build. */
extern s32 func_00594F28(s32, s32, s32);
extern s32 func_L00_005BC9B8(void *);
extern s32 func_L00_005C9F50(s32);
extern s32 func_L01_00585BB0(u8 *object);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern void func_L10_004DCC58(u8 *arg0);

void func_L10_004DCB98(u8 *arg0) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);
    s32 ns;

    if (arg0[0x20] == 0) {
        func_L10_004DCC58(arg0);
    }
    switch (arg0[0x20]) {
    case 1:
        if (arg0[0xBE] & 4) {
            ns = 2;
            goto set_state;
        }
        break;
    case 3:
    default:
        break;
    case 2:
        func_L00_005BC9B8(vars + 0x76);
        if (!func_L01_00585BB0(arg0)) {
            break;
        }
        ns = 3;
    set_state:
        func_L01_00591BD8(arg0, ns, -1);
        break;
    }
    if ((u32)arg0[0x20] >= 2) {
        func_00594F28(0, func_L00_005C9F50(0x255D), *(s16 *)(vars + 0x76));
    }
}
