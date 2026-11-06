#include "common.h"
extern int D_003F0E80[];
extern unsigned char D_003D8C70[];
extern unsigned char D_003F0E8C[];
extern unsigned char D_00243750[];
extern short D_00243470[];
extern unsigned char D_00243380[];
extern unsigned char D_00246150[];
/* Select a record from the active table. */
unsigned char *func_00488D40(int index) {
    int slot;
    if (D_003F0E80[0] == -1) return D_003D8C70;
    slot = D_00243750[index];
    if (slot == 255) return D_003F0E8C;
    if (D_00243470[slot] != index) return D_003F0E8C + D_00246150[slot] * 32;
    return D_003F0E8C + D_00243380[slot] * 32;
}
