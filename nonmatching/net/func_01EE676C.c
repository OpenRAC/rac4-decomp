/* Not matching yet: BYTES 10/112 (tools/try_func.py func_01EE676C --diff). Not part of the build. */
extern void func_01EE9B40(s32 arg0);
void func_01EE66B0(s32, s32);
void func_01EE4D48(s32);
void func_01EDFAE8(void);

/* Calls func_01EE66B0 and func_01EE9B40, clears a word at 0x3A38 through func_01EE4D48 when set, then calls the vtable slot 0x18 of the object at 0x5B20 and clears that pointer, then calls func_01EDFAE8. */
void func_01EE676C(void *arg0) {
    s32 temp_v0;
    void *temp_a0;
    void *vt;

    func_01EE66B0((s32)arg0, 0);
    func_01EE9B40((s32)arg0);
    temp_v0 = *(s32 *)((u8 *)arg0 + 0x3A38);
    if (temp_v0 != 0) {
        func_01EE4D48(temp_v0);
        *(s32 *)((u8 *)arg0 + 0x3A38) = 0;
    }
    temp_a0 = *(void **)((u8 *)arg0 + 0x5B20);
    if (temp_a0 != NULL) {
        vt = *(void **)temp_a0;
        (*(void (**)(void *, s32))((u8 *)vt + 0x18))(temp_a0, 0);
        *(void **)((u8 *)arg0 + 0x5B20) = NULL;
    }
    func_01EDFAE8();
}
