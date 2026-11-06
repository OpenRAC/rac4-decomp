#include "common.h"

s32 func_L41_00447588(s32 class_id)
{
    s32 found = 0;
    switch (class_id) {
    case 0x1B0C:
    case 0x1BDD:
    case 0x1BDE:
        found = 1;
        break;
    }
    return found;
}
