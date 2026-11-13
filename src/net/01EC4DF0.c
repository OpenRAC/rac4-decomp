/* cflags: @ee32-040921 -O2 -G0 */
#include "common.h"

extern void func_01EA6D00(void *);
extern void func_01EA95C0(void *);
void func_01EC4DF0(u8 *arg0) {
    if (arg0 != NULL) {
        func_01EA6D00(arg0 + 0x54);
        func_01EA6D00(arg0 + 0x6C);
        func_01EA95C0(&arg0);
    }
}
