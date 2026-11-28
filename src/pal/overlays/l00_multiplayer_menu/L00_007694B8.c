#include "common.h"
#include "pal/menu_labels.h"

/* Convert a menu identifier into its label-table index. */
s32 func_L00_007694B8(s32 identifier)
{
    switch (identifier) {
#define RETURN_INDEX(identifier, index) case identifier: return index;
        PAL_MENU_LABELS(RETURN_INDEX)
#undef RETURN_INDEX
    default:
        return -1;
    }
}
