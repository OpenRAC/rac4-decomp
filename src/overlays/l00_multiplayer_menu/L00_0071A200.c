#include "common.h"

extern unsigned char D_172A38[];
extern void func_0015C978(void);
extern void func_L00_0071A290(void *, void *, void *);

void func_L00_0071A200(char *arg0) {
    char *temp_v1;
    char *var_v0;
    unsigned char *base;

    base = D_172A38;
    temp_v1 = *(char **)(arg0 + 0x108);
    var_v0 = 0;
    if (temp_v1 != 0) {
        var_v0 = ((temp_v1[0xA8] ^ 1) != 0) ? 0 : temp_v1;
    }
    if (var_v0 == 0) {
        if (base[8] == 0xC8) {
            func_L00_0071A290(arg0, base + 4, base + 0x20);
            func_0015C978();
        } else if (base[8] == 0xC9) {
            func_0015C978();
        } else {
            func_0015C978();
        }
    }
}
