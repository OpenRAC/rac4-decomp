/* Not matching yet: BYTES 4/196 (tools/try_func.py func_L00_00535088 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
extern void func_004FAD28(void *);
extern void func_L00_004F84C8(int, int, int, int, int);
extern void *func_L00_004FACD8(unsigned int);

typedef struct {
    void *f0;
    s32 f4;
} Type1;

/* Size a buffer through measure, fill it, hand it to consume, then free it. */
s32 func_L00_00535088(long (*arg0)(s32, Type1 *), s32 (*arg1)(s32, Type1 *, long), s32 arg2) {
    Type1 buf;
    void *mem;
    s32 ret;

    if (arg2 == 0) {
        return 0;
    }
    mem = func_L00_004FACD8((s32)arg0(arg2, 0) + 0xA);
    if (mem == 0) {
        func_L00_004F84C8(0xD, 0x6A, 0x21, 0, 0);
        return 0;
    }
    buf.f0 = mem;
    {
        long n = arg0(arg2, &buf);
        buf.f0 = mem;
        ret = arg1(0, &buf, n);
    }
    func_004FAD28(mem);
    return ret;
}
