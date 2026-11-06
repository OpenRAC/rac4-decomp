#include "common.h"
typedef struct {
    char p0[0xD0];
    f32 fD0;
    char pD4[24];
} Type1;
extern Type1 D_00307B58[];
/* Stores the float in the selected record. */
void func_004A52C0(s32 index, f32 value)
{
    D_00307B58[index].fD0 = value;
}
