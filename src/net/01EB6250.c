/* cflags: @ee296 -O2 -G0 */
#include "common.h"

/* Calls func_01EB6428 on arg0 for each node of the list at arg0+0xC, following the link word at +4. */
extern void func_01EB6428(void *, void *);

void func_01EB6250(s32 *arg0) {
    s32 *var_s0;
    s32 *var_a1;

    if (arg0 != NULL) {
        if (arg0[2] != 0 && arg0[0] != 0) {
            var_s0 = (s32 *)arg0[3];
            if (var_s0 != NULL) {
                var_a1 = var_s0;
                do {
                    func_01EB6428(arg0, var_a1);
                    var_s0 = (s32 *)var_s0[1];
                    var_a1 = var_s0;
                } while (var_s0 != NULL);
            }
        }
    }
}
