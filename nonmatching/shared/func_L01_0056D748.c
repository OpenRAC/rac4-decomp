/* Not matching yet: BYTES 33/140 (tools/try_func.py func_L01_0056D748 --diff). Not part of the build. */
typedef int (*fn_0056D748)(int, int);

int func_L01_0056D748(int *arg0, fn_0056D748 arg1, int arg2)
{
    int i;
    if (arg1 == 0) {
        return 0;
    }
    for (i = 0; i < arg0[0x10]; i++) {
        arg1(arg0[i], arg2);
    }
    return 1;
}
