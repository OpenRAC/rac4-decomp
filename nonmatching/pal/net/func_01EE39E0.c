/* Not matched: PAL SCES_532.85.
 * SIZE ours 52 / disc 56. 1 actual placement(s).
 * Forwarded object/name parameters and pointer return follow the actual target/callee/caller chain. Native retains an extra traversal copy and distinct plain-branch delay scheduling; still SIZE52/56.
 * Reproduce: python3 tools/check_func.py --version pal func_01EE39E0 nonmatching/pal/net/func_01EE39E0.c --diff
 */
#include "common.h"

void *func_01EE3974(void *object, const char *name);

/* Keep the lookup result for a null exit while following a separate link local. */
void *func_01EE39E0(void *object, const char *name) {
    void *result;
    void *link;

    result = func_01EE3974(object, name);
    link = result;
    if (link != NULL) {
        link = *(void **)((s8 *)link + 8);
        result = NULL;
        if (link != NULL) {
            return *(void **)((s8 *)link + 0x28);
        }
    }
    return result;
}
