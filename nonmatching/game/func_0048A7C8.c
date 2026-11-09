/* Not matching yet: BYTES 7/232 (tools/try_func.py func_0048A7C8 --diff). Not part of the build. */
extern s32 func_00138D70(s32);
extern s32 func_00157F98(void);
extern void func_0048A498(void *, f32);
extern s32 func_0048A798(void *unused0, void *array);
extern void func_0048A950(void *arg0);
extern f32 D_0021DE04;
typedef struct { u8 pad0[8]; u8 f8; u8 pad9[0x47]; } Type1;
extern Type1 D_355DC0[];

// Pumps func_0048A498 until the three records are done or the count runs out, then resets live entries.
void func_0048A7C8(void *arg0, void *arg1, s32 count, void (*cb)(s32), s32 cbArg) {
    Type1 *p;

    while (!func_0048A798(arg0, arg1) && count != 0) {
        if (cb != 0) {
            cb(cbArg);
        }
        count--;
        func_0048A498(arg0, D_0021DE04);
        func_00157F98();
        func_00138D70(0);
    }
    if (!func_0048A798(arg0, arg1)) {
        p = D_355DC0;
        do {
            if (p->f8 != 0) {
                func_0048A950(p);
            }
            p++;
        } while ((s32)p < (s32)(D_355DC0 + 3));
    }
}
