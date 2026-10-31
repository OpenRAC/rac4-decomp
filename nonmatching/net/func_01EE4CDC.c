/* Not matching yet: BYTES 12/108 (tools/try_func.py func_01EE4CDC --diff). Not part of the build. */
/* Clears the state words of arg0 after calling the callback at 0x10 with the word at 0x4, if one is set. */
void func_01EE4CDC(void *arg0) {
    void (*temp_v0)(s32);

    temp_v0 = *(void (**)(s32))((u8 *)arg0 + 0x10);
    if (temp_v0 != NULL) {
        temp_v0(*(s32 *)((u8 *)arg0 + 0x4));
    }
    *(s32 *)((u8 *)arg0 + 0x1C) = 0;
    *(s32 *)((u8 *)arg0 + 0x20) = 0;
    *(s32 *)((u8 *)arg0 + 0x24) = 0;
    *(s32 *)((u8 *)arg0 + 0x28) = 0;
    *(s32 *)((u8 *)arg0 + 0x2C) = 0;
    *(s32 *)((u8 *)arg0 + 0x30) = 0;
    *(s32 *)((u8 *)arg0 + 0x38) = 0;
    *(s32 *)((u8 *)arg0 + 0x3C) = 0;
    *(s32 *)((u8 *)arg0 + 0x44) = 0;
    *(s32 *)((u8 *)arg0 + 0x48) = 0;
    *(s32 *)((u8 *)arg0 + 0x54) = 0;
    *(s32 *)((u8 *)arg0 + 0x58) = 0;
    *(s32 *)((u8 *)arg0 + 0x5C) = 0;
    *(s32 *)((u8 *)arg0 + 0x60) = 0;
}
