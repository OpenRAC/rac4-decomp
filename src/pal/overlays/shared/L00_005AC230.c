#include "common.h"

typedef struct {
    s32 value;          
    s16 key;            
    char pad06[10];
} Rec_2e36f8;
extern s32 D_0023E040[];

/* PAL: from rac3-decomp's func_L01_004000C0 */
s32 func_L00_005AC230(s32 key)
{
    Rec_2e36f8 *entry;
    s32 count = D_0023E040[4];
    s32 i;
    if (count > 0) {
        i = 0;
        entry = (Rec_2e36f8 *)D_0023E040[3];
        do {
            if (entry->key == key)
                return entry->value;
            entry++;
            i++;
        } while (i < count);
    }
    return 0;
}
