/* Not matching yet: BYTES 12/88 (tools/try_func.py func_01EDB3E0 --diff). Not part of the build. */
/* packs six word arguments into a 24-byte struct and returns it through the hidden pointer */
typedef struct { u8 b[24]; } Type1;

Type1 func_01EDB3E0(s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    Type1 r;

    *(s32 *)(r.b + 0x0) = a1;
    *(s32 *)(r.b + 0x4) = a2;
    *(s32 *)(r.b + 0x8) = a3;
    *(s32 *)(r.b + 0xC) = a4;
    *(s32 *)(r.b + 0x10) = a5;
    *(s32 *)(r.b + 0x14) = a6;
    return r;
}
