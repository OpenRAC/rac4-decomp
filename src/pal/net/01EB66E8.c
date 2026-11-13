/* cflags: @ee296 -O2 -G0 */
#include "common.h"

/* Return the last node of the observed allocator-backed list. */


void *func_01EB66E8(void *arg0) {
    void *var_v0;
    void *var_v1;

    var_v1 = NULL;
    if ((arg0 != NULL) && ((*(void **)((s8 *)(arg0) + (8))) != NULL) && ((*(u32 *)((s8 *)(arg0) + (0))) != 0)) {
        var_v0 = (*(void **)((s8 *)(arg0) + (0xC)));
        if (var_v0 != NULL) {
            do {
                var_v1 = var_v0;
                var_v0 = NULL;
                if (var_v1 != NULL) {
                    var_v0 = (*(void **)((s8 *)(var_v1) + (4)));
                }
            } while (var_v0 != NULL);
        }
    }
    return var_v1;
}
