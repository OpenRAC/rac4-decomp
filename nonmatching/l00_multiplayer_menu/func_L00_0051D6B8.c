/* Not matching yet: BYTES 3/444 (tools/try_func.py func_L00_0051D6B8 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern s32 func_0051B498(void);
extern s32 func_00540E70(s32);
extern void func_L00_004F84C8(int, int, int, int, int);
extern s32 func_L00_0051A450(s32 arg0, s32 arg1, char *arg2, s32 arg3);
extern void func_L00_0051A668(s32);
extern void func_L00_005409A0(s32, s32, s32 *, s32, s32);
extern s32 func_L00_00540A90(s32, s32, s32 *);
extern s32 func_L00_00540C08(s32 base);
extern s32 func_L00_00540C10(s32, s32, s32, char *, s32, s32, char *, s32);
extern s32 func_L00_00541080(char *, s32, s32);

s32 func_L00_0051D6B8(s32 arg0, s32 arg1, s64 *arg2, s32 (*arg3)(char *, s32, s32)) {
    char key[0x20];
    char buf[0x400];
    s32 len;
    s32 total;
    s64 val;
    s32 n;
    s32 a;
    s32 b;
    s32 ok;

    val = *arg2;
    if (func_00540E70(arg0) == 0) {
        return 1;
    }
    if (arg3 == 0) {
        n = func_L00_00541080(buf, 0x400, 0);
    } else {
        n = arg3(buf, 0x400, 0);
    }
    if (n <= 0) {
        func_L00_004F84C8(9, 0x6A, 0x68, 0, 0);
        return 0;
    }
    a = func_00540E70(arg0);
    b = func_0051B498();
    if (func_L00_00540C10(a, b, func_L00_00540C08(arg0), buf, n, 1, key, 0) == 0) {
        return 0;
    }
    total = (s32)val;
    if (func_L00_0051A450(arg0, 0, key, 0) == 0) {
        return 0;
    }
    func_L00_005409A0(arg0, arg1, &len, arg1, total);
    ok = func_L00_00540A90(arg0, arg1 + len, &total);
    func_L00_0051A668(arg0);
    func_0011A518(buf, 0, 0x400);
    func_0011A518(key, 0, 0x20);
    total = len + total;
    if (ok == 0) {
        func_L00_004F84C8(9, 0x6A, 0x65, 0, 0);
        return 0;
    }
    *arg2 = total;
    return 1;
}
