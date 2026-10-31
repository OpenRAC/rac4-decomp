/* Not matching yet: BYTES 15/108 (tools/try_func.py func_01F03E40 --diff). Not part of the build. */
typedef struct Type1 {
    s32 f0;
    u8 pad4[0xC];
    s32 f10;
    u8 pad14[0x9C];
    s32 fB0;
    s32 fB4;
} Type1;

extern void func_01EF382C(void);
extern s32 func_01EE3A18(s32 a0, void *a1);
extern void func_01F03E04(void *a0);
extern void func_01F06988(s32 a0);
extern s32 D_00170BB8[];
extern s32 D_0019E010[];

/* Stores two table addresses in the object, runs the setup calls, and records the lookup result. */
void func_01F03E40(Type1 *arg0) {
    s32 temp_v0;

    func_01EF382C();
    arg0->fB0 = (s32)D_00170BB8;
    func_01F03E04(arg0);
    temp_v0 = func_01EE3A18(arg0->f0, D_0019E010);
    arg0->fB4 = temp_v0;
    if (temp_v0 != 0) {
        arg0->f10 = 1;
        func_01F06988(temp_v0);
        return;
    }
    arg0->f10 = 0;
}
