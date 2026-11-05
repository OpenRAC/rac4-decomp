/* Not matching yet: BYTES 1/68 (variadic spill pointer uses sp+0x80; retail sp+0x50; tools/try_func.py func_0011C750 --diff) (tools/try_func.py func_0011C750 --diff). Not part of the build. */
#include "common.h"

typedef char *va_list;

extern void func_00123DF8(s32, s32, va_list);

void func_0011C750(s32 arg0, s32 arg1, ...) {
    va_list args;

    args = __builtin_next_arg(arg1);
    func_00123DF8(arg0, arg1, args);
}
