#include "common.h"
#include "pal/menu_labels.h"

extern const char *D_L00_004EEAC8[];
extern const char D_L00_002217E8[];
extern void func_L00_00769260(void);

/* Load the cached menu label or the fallback text. */
const char *func_L00_00769340(s32 identifier)
{
    const char *label;

    if (D_L00_004EEAC8[0] == 0) {
        func_L00_00769260();
    }

    switch (identifier) {
#define LOAD_LABEL(identifier, index) case identifier: label = D_L00_004EEAC8[index]; break;
        PAL_MENU_LABELS(LOAD_LABEL)
#undef LOAD_LABEL
    default:
        label = D_L00_002217E8;
        break;
    }
    return label;
}
