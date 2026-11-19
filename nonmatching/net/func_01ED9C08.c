/* Not matching yet: BYTES 53/88 (tools/try_func.py func_01ED9C08 --diff). Not part of the build. */
s32 func_01ED9C08(u32 arg0, u32 arg1) {
    switch (arg0) {
    case 4:
    case 5:
        if (arg1 < 2)
            return 0;
        break;
    case 3:
    case 6:
        break;
    default:
        return 0;
    }
    return 1;
}
