/* Not matching yet: BYTES 3/216 (tools/try_func.py func_004C9090 --diff). Not part of the build. */
extern s32 func_0045E038(s32);
extern void func_00497980(s32 arg0);
extern void func_0049E790(s32, s32, void (*)(void *), s32, f32, s32, s32, s32);
extern void func_004C8FB0(void *);
extern s32 func_004E6FA0(s32 *arg0);
extern s32 func_00505B20(void);
extern s32 D_30E494[];

// checks the selected table entry and either finishes or queues a callback
void func_004C9090(void) {
    u8 *base;
    u8 *entry;
    s32 *obj;
    s32 idx;
    s32 a;

    base = (u8 *)D_30E494;
    if (*(s32 *)(base + 0x50) != 0) {
        idx = *(s32 *)(base + 0x54);
        entry = NULL;
        if (idx >= 0) {
            entry = *(u8 **)(base + 0x34) + idx * 0x18;
        }
        obj = *(s32 **)(entry + 8);
        if (func_004E6FA0(obj) != 0) {
            if (obj[2] <= 0 || obj[0] == 1) {
                func_004C8FB0((void *)1);
            } else {
                a = func_00505B20();
                func_0049E790(a, func_0045E038(0x8D0), func_004C8FB0, 3, -1.0f, 0, 0, 0);
            }
        } else {
            func_00497980(4);
        }
    }
}
