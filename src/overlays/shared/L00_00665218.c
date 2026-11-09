#include "common.h"

extern u8 D_00329550[];
void func_L00_00665160(void *table);

/* Applies the record table at D_00329550 (func_L00_00665160 returns nothing). */
void func_L00_00665218(void) {
    func_L00_00665160(D_00329550);
}
