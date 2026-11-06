/* Not matching yet: BYTES 8/204 (tools/try_func.py func_004A98C0 --diff). Not part of the build. */
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00504238(s32, f32, f32);
extern void func_00505410(s32, f32);
extern s32 func_00505B20(void);
extern s32 D_221650;
typedef struct { char pad[0x88]; f32 f88; } Type1;
extern char D_308108[];
/* Sets two element values from the current slot's fraction and flags the slot. */
void func_004A98C0(void) {
    s32 off = func_00505B20() * 0xB8;
    f32 t = ((Type1 *)(D_308108 + off))->f88;
    f32 u = 1.0f - t;
    func_00504238(func_004A1A60(&D_221650, 1), u * -0.1f + 0.5f, u * 0.0f + 0.5f);
    func_00505410(func_004A1A60(&D_221650, 1), t);
    *(s32 *)(D_308108 + off + 0x98) |= 0x100;
}
