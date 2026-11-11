#include "common.h"

extern int func_0011A930(int, void (*)(void), int);
typedef unsigned int Rac2Native_74a5d71aacb394c6_u32;
typedef struct {
    Rac2Native_74a5d71aacb394c6_u32 first[64];
    Rac2Native_74a5d71aacb394c6_u32 second[64];
    unsigned char gap[0x20];
    int count;
    Rac2Native_74a5d71aacb394c6_u32 current;
} Rac2Native_74a5d71aacb394c6_ExtraIndexState48;
extern int func_0011A930(int, void (*)(void), int);

/* PAL: from rac3-decomp's func_L01_004CAE60 */
void func_L01_006402B0(Rac2Native_74a5d71aacb394c6_ExtraIndexState48 *state, int index) {
    state->first[index] = 0;
    state->second[index] = 0;
    if (--state->count == 0) {
        state->current = 0;
    }
}
