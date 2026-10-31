/* Not matching yet: BYTES 6/72 (tools/try_func.py func_01EEFE4C --diff). Not part of the build. */
extern void func_01EA7408();
extern void func_01EA7538();
extern s32 func_01EA7D48(void);
extern void func_01EA8C08(void *, s64);

typedef struct __attribute__((packed)) {
    u64 v;
} Type1;

/* Calls three helpers, copies 8 bytes of a stack buffer through a temporary, and passes them to func_01EA8C08. */
void func_01EEFE4C(void) {
    Type1 buf;
    u8 sp10[0x20];
    Type1 tmp;

    func_01EA7408();
    func_01EA7538();
    ((s32 (*)(void *))func_01EA7D48)(&buf);
    tmp = buf;
    func_01EA8C08(sp10, tmp.v);
}
