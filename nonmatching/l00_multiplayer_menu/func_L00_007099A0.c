/* Not matching yet: BYTES 8/32 (tools/try_func.py func_L00_007099A0 --diff). Not part of the build. */
s32 D_00220A10 = 0;
s32 D_00220A14 = 0;

/* Append the object to the list, setting its link and the head. */
void func_L00_007099A0(s32 arg0) {
    s32 tail = D_00220A14;

    if (tail != 0) {
        (*(s32 *)((u8 *)tail + 0x19C)) = arg0;
    }
    if (D_00220A10 == 0) {
        D_00220A10 = arg0;
    }
    D_00220A14 = arg0;
}
