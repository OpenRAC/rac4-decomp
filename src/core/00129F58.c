/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern int func_0012D420(void);
extern void func_0012D470(void);

/* from rac2-decomp's func_0011D140 */
void *func_00129F58(void *arg0) {
    char *a = (char *)arg0;
    int n;
    char *p;
    int i;
    int id;
    int v;
    func_0012D420();
    n = *(int *)(a + 0x8);
    i = 0;
    p = *(char **)(a + 0x4);
    while (i < n) {
        if ((*(int *)(p + 0x10) & 1) == 0) {
            *(int *)(p + 0x10) = (i << 16) | 5;
            v = *(int *)a + 1;
            *(int *)a = v;
            if (v == 1) {
                *(int *)a = v + 1;
                id = 1;
            } else {
                id = v;
            }
            *(char **)(p + 0x14) = p;
            *(int *)(p + 0x18) = id;
            func_0012D470();
            return p;
        }
        i++;
        p += 0x40;
    }
    func_0012D470();
    return 0;
}
