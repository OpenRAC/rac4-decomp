#include "common.h"
#include "pal/mode_definition_0054B050.h"


s32 func_0054B628(s32 item, s32 mode)
{
    PalModeDefinition definition;
    s32 i;

    definition = *func_0054B050(mode);
    for (i = 0; i < 10; i++) {
        if (definition.allowed[i] == item) {
            return 1;
        }
    }
    return 0;
}
