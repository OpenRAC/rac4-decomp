/* Not matching yet: BYTES 10/232 (tools/try_func.py func_004B0A00 --diff). Not part of the build. */
extern int D_00221718;
extern int D_003095C0[];
s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00504238(s32, f32, f32);
extern void func_00504550(s32, f32 *, f32 *);
extern void func_00504648(s32, f32 *, f32 *);
extern s32 func_00504840(s32, f32, f32, f32, f32);
extern void func_00505118(s32, f32 *, f32 *, f32 *, f32 *);

void func_004B0A00(void)
{
    f32 a[4];
    f32 x, y, z, w;
    f32 off;

    func_00504648(func_004A1A60(&D_00221718, 3), &a[0], &a[1]);
    off = (f32)D_003095C0[0] * a[1];
    func_00504550(func_004A1A60(&D_00221718, 0x22), &a[2], &a[3]);
    func_00504238(func_004A1A60(&D_00221718, 0x22), a[2], a[3] + off);
    func_00505118(func_004A1A60(&D_00221718, 2), &x, &y, &z, &w);
    func_00504840(func_004A1A60(&D_00221718, 2), x, y, z, w + off);
}
